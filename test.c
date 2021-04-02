#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	c = 'a';
	char *ptr;
	ptr = NULL;
	ptr = &c;
	printf("ptr = %c\n", *ptr);
	free(ptr);
	printf("success\n");
}
