#include<bits/stdc++.h>
using namespace std;
int ans;
string st;
int main()
{
	getline(cin,st);
	if(st[0]==st[st.size()-1]) ans++;
	if(st.size()%2==1) ans++;
	if(ans==1) cout<<"First\n";
	  else cout<<"Second\n";
	exit(0);
}