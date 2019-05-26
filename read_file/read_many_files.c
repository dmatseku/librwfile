#include <rwfile.h>

static void non_close(int fd)
{
	fd = 0;
}

static void	close_fd(int fd)
{
	close(fd);
}

char**		read_many_files(int *fd, size_t count, char closefd)
{
	size_t	i;
	char**	res;
	char*	tmp;
	void	(*f)(int);

	i = 0;
	f = non_close;
	if (closefd)
		f = close_fd;
	CHECK((res = (char**)malloc(sizeof(char*) * count)));
	while (i < count)
	{
		CHECK((tmp = read_all_file(fd[i])));
		res[i] = tmp;
		f(fd[i]);
		i++;
	}
	if (closefd)
		FREE(fd);
	return (res);
}