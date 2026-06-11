#include<bits/stdc++.h>
using namespace std;
string st,st1,ans,sum;
int main()
{
	cin>>st;
	st1=st;
	reverse(st.begin(),st.end());
	
	for (int i=0;i<st.size();i++) {
		if(st[i]=='b') {
			st[i]='d'; continue;
		}
		if(st[i]=='d') {
			st[i]='b'; continue;
		}
		if(st[i]=='p') {
			st[i]='q'; continue;
		}
		if(st[i]=='q') {
			st[i]='p'; continue;
		}
    }
	if(st1==st) cout<<"Yes";
	else cout<<"No";
    return 0;
}