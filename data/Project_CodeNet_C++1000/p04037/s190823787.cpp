#include<bits/stdc++.h>
using namespace std;
int n,a[100100];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int x=0,y=0;
    while (y+1<n&&x+1<a[y+2]&&x+1<a[y+1])
    {
    	x++;y++;
    }
    //走到边界处 
	int xx=(a[y+1]-x)%2,yy=1;
	//xx+1即为由上走出界的步数，yy同理 
	for (int i=x;i<=n;i++)
	{
		yy^=1;
		if (x>=a[i+1]) break;
	}
	if ((!xx)||(!yy)) cout<<"First\n";else cout<<"Second";
	return 0;
}