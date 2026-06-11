#include <stdio.h>
using namespace std ; 
int main() {
	int a;
	int b;
	char op;
	scanf("%d %c %d", &a, &op, &b);
	
	if (op == '+')
	{
		printf("%d\n", a + b);
	}
	else if (op == '-')
	{
		printf("%d\n", a - b);
	}
}
