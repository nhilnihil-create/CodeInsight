#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int H,W;
string s[30][30];
string tmp = "snuke";
int main()
{
	scanf("%d%d",&H,&W);
	for(int i=1;i<=H;i++)
	for(int j=1;j<=W;j++)
	{
		cin>>s[i][j];
	}
	for(int i=1;i<=H;i++)
	for(int j=1;j<=W;j++)
	if(s[i][j] == tmp)
	{
		char y = j+'A'-1;
		int x = i;
		printf("%c%d",y,x);
		break;
	}
	return 0;
}