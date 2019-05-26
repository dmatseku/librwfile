#include <rwfile.h>

char*	read_all_file(int fd)
{
	char*	res;
	char*	tmp;
	char*	buff;
	int		read_res;
	size_t  prev_count;

	res = 0;
	prev_count = 0;
	CHECK((buff = (char*)malloc(sizeof(char) * (BUFF_ALL + 1))));
	bzero(buff, BUFF_ALL + 1);
	while ((read_res = read(fd, buff, BUFF_ALL)))
	{
		CHECK((read_res >= 0));
		tmp = res;
		CHECK((res = (char*)malloc(sizeof(char) * (prev_count + read_res + 1))));
		prev_count += read_res;
		bzero(res, prev_count + 1);
		if (tmp)
			strcat(res, tmp);
		strcat(res, buff);
		FREE(tmp);
		bzero(buff, BUFF_ALL);
	}
	FREE(buff);
	return (res);
}