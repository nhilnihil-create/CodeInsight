#include<bits/stdc++.h>
using namespace std;
string s,st;
int p;
int main()
{
	cin>>s;
	st=s;
	reverse(st.begin(),st.end());
	for (int i=0; i<s.size(); i++)
	{
		if (st[i]=='b') st[i]='d';
		else if (st[i]=='d') st[i]='b';
		else if (st[i]=='p') st[i]='q';
		else st[i]='p';
	}
	if (st==s) cout<<"Yes"<<endl; else cout<<"No"<<endl;
	return 0;
}