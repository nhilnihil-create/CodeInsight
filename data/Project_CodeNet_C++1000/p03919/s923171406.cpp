#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d\n",&n,&m);
	string s;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>s;
		if(s=="snuke")
		{
			printf("%c%d\n",j+'A'-1,i);
			break;
		}
	}
	return 0;
}