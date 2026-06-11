#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int cnt=0;
	string s,t="CODEFESTIVAL2016";
	cin>>s;
	for(int i=0;i<16;i++)
	{
		if(s[i]!=t[i])cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}