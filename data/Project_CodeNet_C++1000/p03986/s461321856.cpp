#include<iostream>
#include<string.h>
using namespace std;

char c[200099];
int main()
{
	int i=0;
	while(scanf("%c",&c[i])!=EOF)
	{
		if(i>0)
		{
			if(c[i-1]=='S'&&c[i]=='T')
			i=i-2;
		}
		i++;
	}
	cout<<i-1<<endl;
	return 0;
}