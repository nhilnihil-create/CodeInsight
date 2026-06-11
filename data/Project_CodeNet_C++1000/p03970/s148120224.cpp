#include<bits/stdc++.h>
using namespace std;
char a;
string s="CODEFESTIVAL2016";
int sum;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(int i=0;i<16;i++)
	{
		cin>>a;
		if(a!=s[i]) sum++;
	}
	cout<<sum<<endl;
	return 0;
}

