#include<stdio.h>
int main()
{
	int a,b,c;
	while(~scanf("%d %d", &a, &b))
	{
		if(a<=0 && b>=0)
			printf("Zero\n");
		else if(a<0)
		{
			c=b-a;
			if(c==0 || c%2==1)
				printf("Positive\n");
			else
				printf("Negative\n");
		}
		else
			printf("Positive\n");		
	}

	return 0;
}