#include<stdio.h>
int main()
{
	int i,a,b,n,cp,co;
	char str[100001];
	while(~scanf("%d %d %d", &n, &a, &b)){
		scanf("%s", str);
		cp=co=0;
		for(i=0; i<n; i++)
		{
			if(cp<a+b)
			{
				if(str[i]=='a')
				{
					cp++;
					printf("Yes\n");
				}
				else if(str[i]=='b' && co<b)
				{
					cp++;
					co++;
					printf("Yes\n");
				}
				else
					printf("No\n");
			}
			else
				printf("No\n");
		}
	}
}