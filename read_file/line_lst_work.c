#include <rwfile.h>

t_list*		find(int fd, t_list* lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (0);
}

void		list_remove(t_list** lst, t_list* elem)
{
	t_list* tmp;
	t_list* tmp1;

	tmp = *lst;
	if (tmp == elem)
	{
		*lst = tmp->next;
		FREE(tmp->buffer);
		close(tmp->fd);
		FREE(tmp);
		return ;
	}
	while (tmp->next != elem)
		tmp = tmp->next;
	tmp1 = tmp->next;
	tmp->next = tmp1->next;
	FREE(tmp1->buffer);
	close(tmp1->fd);
	FREE(tmp1);
}

t_list*		add(int fd, t_list** lst)
{
	t_list*	data;

	CHECK((data = list_create(fd)));
	list_add_end(lst, data);
	return (data);
}

