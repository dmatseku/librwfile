#include <rwfile.h>

char**		read_many_files(int const * const restrict fd, const size_t count)
{
	size_t			i;
	char* *const	res = (char**)malloc(sizeof(char*) * count);
	char*			tmp;

	i = 0;
	if (!res)
		return (0);
	while (i < count)
	{
		if (!(tmp = read_all_file(fd[i])))
			return (0);
		res[i] = tmp;
		i++;
	}
	return (res);
}