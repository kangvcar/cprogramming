#include <stdio.h>
#define MAXLINE	1000
#define LONGLINE	80

int getlinee(char line[], int maxline);
main()
{
	int len;
	char line[MAXLINE];
	while((len = getlinee(line, MAXLINE)) > 0)
		if(len > LONGLINE)
			printf("%s", line);
	return 0;
}
int getlinee(char s[], int lim)
{
	int c, i, j;
	j = 0;
	for(i=0; (c = getchar()) != EOF && c != '\n'; ++i)
		if(i < lim-2){
			s[j] = c;
			++j;
		}
		if(c == '\n'){
			s[j] = c;
			++j;
			++i;
		}
		s[j] = '\0';
	return i;
}
