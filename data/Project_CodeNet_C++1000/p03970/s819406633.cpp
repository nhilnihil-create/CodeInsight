#include<bits/stdc++.h>
using namespace std;
const string str="CODEFESTIVAL2016";
int main()
{
	string s;
	cin>>s;
	int cnt;
	for(int i=0;i<=16;i++)
		if(s[i]!=str[i])
			cnt++;
	cout<<cnt<<"\n";
	return 0;
}