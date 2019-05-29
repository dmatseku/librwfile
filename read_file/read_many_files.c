#include <rwfile.h>

char**		read_many_files(int *fd, size_t count)
{
	size_t	i;
	char**	res;
	char*	tmp;

	i = 0;
	CHECK((res = (char**)malloc(sizeof(char*) * count)));
	while (i < count)
	{
		CHECK((tmp = read_all_file(fd[i])));
		res[i] = tmp;
		i++;
	}
	return (res);
}