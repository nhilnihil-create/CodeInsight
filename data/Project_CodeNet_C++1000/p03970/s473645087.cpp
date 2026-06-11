#include<bits/stdc++.h>
using namespace std;
int ans;
string s,a;
int main()
{
	getline(cin,s);
	a="CODEFESTIVAL2016"; 
	for(int i=0;i<s.size();i++)
		if(s[i]!=a[i]) ans++;
	cout<<ans<<endl;
	return 0;
}

