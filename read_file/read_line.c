#include <rwfile.h>


static size_t	str_len(char const * const str, const size_t i, const size_t len)
{
	size_t res;

	res = i;
	while (res < len && str[res] != '\n')
		res++;
	res -= i;
	return (res);
}

static int	realoc_str(char** str, char* tmp, const size_t size, size_t* const size_all)
{
	char* prev;
	size_t i;

	prev = *str;
	CHECK((*str = (char*)malloc(sizeof(char)
			* (unsigned long)(*size_all + size + 1))));
	i = 0;
	while (i < *size_all)
	{
		(*str)[i] = prev[i];
		i++;
	}
	FREE(prev);
	(*str)[i] = 0;
	strncat(*str, tmp, size);
	*size_all += size;
	return (1);
}

static int	create_line(t_list* const elem, char** str)
{
	size_t	size;
	size_t	size_all;

	size_all = 0;
	while (elem->i < elem->len && elem->buffer[elem->i] == '\n')
		elem->i++;
	while (elem->i == elem->len)
	{
		bzero(elem->buffer, BUFF_LINE);
		elem->len = read(elem->fd, elem->buffer, BUFF_LINE);
		if (elem->len <= 0)
			return (elem->len);
		elem->i = 0;
		while (elem->i < elem->len && elem->buffer[elem->i] == '\n')
			elem->i++;
	}
	while (1)
	{
		size = str_len(elem->buffer, elem->i, elem->len);
		if (!size)
			return (1);
		CHECK(realoc_str(str, elem->buffer + elem->i, size, &size_all));
		elem->i += size;
		if (elem->i < elem->len)
			return (1);
		else
		{
			bzero(elem->buffer, BUFF_LINE);
			elem->len = read(elem->fd, elem->buffer, BUFF_LINE);
			elem->i = 0;
			if (elem->len <= 0)
				return ((elem->len == 0 ? 1 : -1));
		}
	}
}

int		read_line(const int fd, char** str)
{
	static t_list*	fds = 0;
	t_list*			elem;
	int				res;

	if (fd < 0)
		return (-1);
	elem = find(fd, fds);
	*str = 0;
	if (!elem)
	{
		CHECK((elem = add(fd, &fds)));
	}
	res = create_line(elem, str);
	if (!(*str))
	{
		list_remove(&fds, elem);
		return (0);
	}
	if (res < 0)
	{
		FREE((void*)(*str));
		*str = 0;
		return (-1);
	}
	return (1);
}
