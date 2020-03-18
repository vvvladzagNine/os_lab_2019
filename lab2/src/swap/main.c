#include <stdio.h>


void swap(char *left, char *right)
{
  char temp = *left;
  *left = *right;
  *right = temp;
}

int main()
{
	char ch1 = 'a';
	char ch2 = 'b';

	swap(&ch1, &ch2);

	printf("%c %c\n", ch1, ch2);
	return 0;
}


