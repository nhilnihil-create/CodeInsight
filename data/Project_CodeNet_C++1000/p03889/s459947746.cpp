#include<cstdio>
#include<cstring>
using namespace std;
char a[10000000],b[10000000];
int main()
{
    int c,d;
    gets(a+1);
    c=strlen(a+1);
    for(int i=1;i<=c;i++)
    {
    	b[i]=a[c+1-i];
	}
	for(int i=1;i<=c;i++)
    {
    	if(b[i]=='b')
    	b[i]='d';
    	else
    	{
    		if(b[i]=='d')
    	    b[i]='b';
    	    else
    	    {
    	    	if(b[i]=='p')
    	        b[i]='q';
    	        else
    	        {
    	        	if(b[i]=='q')
    	            b[i]='p';
				}
			}
		}
	}
	for(int i=1;i<=c;i++)
    {
    	if(a[i]==b[i]&&i==c)
    	{
    		printf("Yes");
		}
	    else
		{
			if(a[i]!=b[i])
			{
				printf("No");
				break;
			}
		}
		
	}
	
    return 0;
} 