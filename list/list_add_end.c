#include <rwfile.h>

void	list_add_end(t_list* *const restrict lst, t_list* const restrict elem)
{
	t_list* tmp;

	if (!*lst)
	{
		*lst = elem;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
}
