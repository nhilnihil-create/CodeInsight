#include<bits/stdc++.h>
#define itn int
#define For(a,b,c,t)  for(ri a=b;a<=c;a+=t)
#define ri register int
#define Memset(a,b)  memset(a,b,sizeof(a))
#define li long long
#define il inline
using namespace std;
string a,b;
int main()
{
	cin>>a;
	int l=a.size();
	b=a;
	//printf("\n");
	For(i,0,l-1,1)
	{
		if(b[i]=='b')
		  b[i]='d';
		else if(b[i]=='d')
		  b[i]='b';
		else if(b[i]=='q')
		  b[i]='p';
		else if(b[i]=='p')
		  b[i]='q';
		//printf("%c",b[i]);
	}
	//printf("\n");
	For(i,0,l-1,1)
	{
		if(a[i]!=b[l-1-i])
		{
			printf("No");
			exit(0);
		}
	}
	printf("Yes");
	return 0;
}