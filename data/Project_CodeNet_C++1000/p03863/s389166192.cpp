#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string s; cin>>s;
	int len = s.size();
	int ans = 0;
	if(s[0] == s[len-1]) ans++;
	if(len%2 == 0) ans++;
	if(ans == 0 || ans == 2) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}
