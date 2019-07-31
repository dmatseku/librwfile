#include <rwfile.h>

t_list*		find(const int fd, t_list *restrict lst)
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

void		list_remove(t_list** const lst, t_list const * const elem)
{
	t_list* tmp;
	t_list* tmp1;

	tmp = *lst;
	if (tmp == elem)
	{
		*lst = tmp->next;
		free(tmp->buffer);
		close(tmp->fd);
		free(tmp);
		return ;
	}
	while (tmp->next != elem)
		tmp = tmp->next;
	tmp1 = tmp->next;
	tmp->next = tmp1->next;
	free(tmp1->buffer);
	close(tmp1->fd);
	free(tmp1);
}

t_list*		add(const int fd, t_list** const restrict lst)
{
	t_list*	const restrict data = list_create(fd);

	if (!data)
		return (0);
	list_add_end(lst, data);
	return (data);
}

