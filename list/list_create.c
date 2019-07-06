#include <rwfile.h>


t_list	*list_create(const int fd)
{
	t_list * const res = (t_list*)malloc(sizeof(t_list));

	if (!res)
		return (0);
	res->fd = fd;
	CHECK((res->buffer = (char*)malloc(sizeof(char) * (BUFF_LINE + 1))));
	res->buffer[BUFF_LINE] = 0;
	res->i = BUFF_LINE;
	res->len = BUFF_LINE;
	res->next = 0;
	return (res);
}