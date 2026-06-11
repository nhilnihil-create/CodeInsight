#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int cnt=0;
	cin>>s;
	string x;
	x="CODEFESTIVAL2016";
	for(int i=0;i<16;i++)
		if(s[i]!=x[i])cnt++;
	cout<<cnt<<endl;
    return 0;
}
