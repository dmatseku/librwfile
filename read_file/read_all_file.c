#include <rwfile.h>

char*	read_all_file(const int fd)
{
	char*		res;
	char*		tmp;
	char* const	buff = (char*)malloc(sizeof(char) * (BUFF_ALL + 1));
	int			read_res;
	size_t		prev_count;

	res = 0;
	prev_count = 0;
	if (!buff)
		return (0);
	bzero(buff, BUFF_ALL + 1);
	while ((read_res = read(fd, buff, BUFF_ALL)))
	{
		if (read_res < 0)
			return (0);
		tmp = res;
		if (!(res = (char*)malloc(sizeof(char) * (prev_count + read_res + 1))))
			return (0);
		prev_count += read_res;
		bzero(res, prev_count + 1);
		if (tmp)
			strcat(res, tmp);
		strcat(res, buff);
		free(tmp);
		bzero(buff, BUFF_ALL);
	}
	free(buff);
	close(fd);
	return (res);
}