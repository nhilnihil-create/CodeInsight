#include<bits/stdc++.h>
using namespace std;

string p="CODEFESTIVAL2016",a;
int i,ans;
bool f;
int main()
{
	cin>>a;
	for(i=0;i<=15;i++)
	{
		if(a[i]!=p[i])ans++;
	}
	cout<<ans<<endl;
}