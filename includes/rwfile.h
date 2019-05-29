#ifndef RWFILE_H

#define RWFILE_H
#define BUFF_ALL 270
#define BUFF_LINE 270
#define CHECK(x) if (!x) return (0)
#define FREE(x) if (x) free(x)

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_list t_list;

struct		s_list
{
	t_list*	next;
	char*	buffer;
	int		fd;
	int		i;
	int		len;
};

t_list		*list_create(int fd);

void		list_remove(t_list** lst, t_list* elem);

void		list_add_end(t_list** lst, t_list* elem);

char*		read_all_file(int fd);

char**		read_many_files(int *fd, size_t count);

t_list*		find(int fd, t_list* lst);

t_list*		add(int fd, t_list** lst);

int			read_line(int fd, char **str);

#endif
