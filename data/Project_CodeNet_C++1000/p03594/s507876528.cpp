#include<bits/stdc++.h>
using namespace std;
int n,m,d,a,b;
char c[4]={'R','Y','G','B'};
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a=((m+i+j)/d)%2;b=((m+i-j)/d)%2;
			//cout<<a<<" "<<b<<endl;
			printf("%c",c[a*2+b]);
		}
		cout<<endl;
	}
	return 0;
}