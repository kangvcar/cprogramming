#include <stdio.h>
#define MAXLINE 1000	//maximum input line size

int getlinee(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0;
	while((len = getlinee(line, MAXLINE)) > 0){
		printf("%d, %s", len, line);
		if(len > max){
			max = len;
			copy(longest, line);
		}
	}
	if(max > 0)
		printf("%s", longest);
	return 0;
}
/* getlinee: read a line into s, return length */
int getlinee(char s[], int lim)
{
	int c, i, j;
	j = 0;
	for(i=0;(c = getchar()) != EOF && c != '\n'; ++i)
		if(i <lim-2){
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
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	while((to[i] = from[i]) != '\0')
		++i;
}
