#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	char a,b,c;
	string s,t,r;
	cin>>s>>t>>r;
	if(s[s.length()-1]==t[0]&&t[t.length()-1]==r[0])cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}