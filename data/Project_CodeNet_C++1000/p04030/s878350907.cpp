#include<stdio.h>
#include<string.h>
int main()
{
	char inp[11];
	scanf("%s",inp);
	int j=0;
	char out[11]={'\0'};
	int len = strlen(inp);
	for(int i = 0; i < len; i++)
	{
		if(inp[i]=='0')
		{
			out[j]='0';
			j++;
		}
		else if(inp[i]=='1')
		{
			out[j]='1';
			j++;
		}
		else if(inp[i]=='B')
		{
			if(j!=0)
			{
				j--;
				out[j]='\0';
			}
		}
	}
	printf("%s", out);
 	return 0;   
}