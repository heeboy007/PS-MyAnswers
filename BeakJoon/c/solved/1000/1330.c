#include<stdio.h>

int main ()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	
	printf(a < b ? "<" : (a > b ? ">" : "==" ));
	return 0;
}
