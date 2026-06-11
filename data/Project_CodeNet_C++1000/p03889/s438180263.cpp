// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
char a[100010];
bool d=true;
int main(){
	cin>>a;
	int t=strlen(a);
	if(t%2!=0)cout<<"No"<<endl;
	else
	{
		for(int i=0;i<=t/2-1;i++)
		{
			if(a[i]=='b'&&a[t-i-1]!='d')
			{
				d=false;
				break;
			}
			if(a[i]=='d'&&a[t-i-1]!='b')
			{
				d=false;
				break;
			}
			if(a[i]=='q'&&a[t-i-1]!='p')
			{
				d=false;
				break;
			}
			if(a[i]=='p'&&a[t-i-1]!='q')
			{
				d=false;
				break;
			}
		}
		if(d)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}