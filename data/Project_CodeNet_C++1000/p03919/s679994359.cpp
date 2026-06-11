#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int H,W;
string s[30][30];
string tmp = "snuke";
bool flag;
int main()
{
	scanf("%d%d",&H,&W);
	flag = false;
	for(int i=1;i<=H;i++)
	{
	if(flag) break;
	for(int j=1;j<=W;j++)
	{
		cin>>s[i][j];
		//if(flag)continue;
		if(s[i][j] == tmp)
		{
			char y = j+'A'-1;
			int x = i;
			printf("%c%d",y,x);
			flag = true;
			break;
		}
	}
}
	return 0;
}