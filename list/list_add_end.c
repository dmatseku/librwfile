#include <rwfile.h>

void	list_add_end(t_list** lst, t_list* elem)
{
	t_list* tmp;

	tmp = *lst;
	if (!*lst)
	{
		*lst = elem;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
}
