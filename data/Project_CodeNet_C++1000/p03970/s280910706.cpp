#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s="CODEFESTIVAL2016";
	string c;cin>>c;
	int cnt=0;
	for(int i=0;i<=15;i++)
	if(c[i]!=s[i])cnt++;
	cout<<cnt<<endl;
	return 0;
}