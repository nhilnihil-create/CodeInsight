#include<stdio.h>
#include<string.h>
int main()
{
	char command[15], output[15];
	scanf("%s",&command);
	int len = strlen(command);
	int i = 0,j = 0;
	while(len--)
	{
		if(command[j] == 'B')
		{
			if(i > 0)
			{
				i--;
			}
			output[i] = ' ';
			j++;
		}
		else{
			output[i] = command[j];
			i++;
			j++;
		}
	}
	output[i] = '\0';
	printf("%s\n",output);
	return 0;
}