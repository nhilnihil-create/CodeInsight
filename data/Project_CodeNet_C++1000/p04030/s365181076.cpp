#include<stdio.h>
#include<string.h>
 
int main()
{
  	char inp[11];
  	scanf("%s", inp);
 
  	int j = 0;
  	char a[11] = {'\0'};
  	int n = strlen(inp);
  	int i;
  	for(i = 0; i < n; i++)
	{
	    if(inp[i] == '0')
		{
      		a[j]='0';
      		j++;
    	}
		else if (inp[i] == '1')
		{
	      	a[j]='1';
	      	j++;
    	}
		else if (inp[i] == 'B')
		{
      		if(j != 0)
		  	{
	        	j--;
	        	a[j]='\0';
	      	}
    	}
  	}
	  
  	printf("%s", a);
  	return 0;
}