#include "gnl.h"

char *schr(char *s, int c)
{
	if(!s)
		return NULL;
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return NULL;
}
size_t slen(char *s)
{
	if(!s)
		return 0;
	size_t l = 0;
	while (s[l])
		l++;
	return l;
}
void scpy(char *d, char *s)
{
	if(!d || !s)
		return ;
	while(*s)
		*d++ = *s++;
	*d = '\0';
}
char *sdup(char *s)
{
	if(!s)
		return NULL;
	size_t l = slen(s);
	char *d = malloc(l+1);
	if(!d)
		return NULL;
	scpy(d, s);
	return d;
}
char *sjoin(char *s1, char* s2)
{
	if(!s1 || !s2)
		return NULL;
	size_t l1 = slen(s1);
	size_t l2 = slen(s2);
	char *j = malloc(l1+l2+1);
	if(!j)
		return NULL;
	scpy(j,s1);
	scpy(j+slen(s1), s2);
	if(s1)
		free(s1);
	return j;
}

char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE+1];
	char *line;
	char *nline;
	int br;

	line=sdup(buff);
	if(!line)
		return NULL;
	while(!(nline=schr(line, '\n')) && (br=read(fd,buff,BUFFER_SIZE)))
	{
		buff[br]='\0';
		line=sjoin(line,buff);
	}
	if(slen(line) == 0)
		return (free(line), NULL);
	if (nline)
	{
		scpy(buff, nline+1);
		*(nline+1) = '\0';
	}
	else
		buff[0] = '\0';
	return line;
}


int	main(void)
{
	int     fd;
	char    *str;
	int     i;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	while(++i < 10)
	{
		str = get_next_line(fd);
		printf("line %i:%s", i, str);
	}
	return (0);
}