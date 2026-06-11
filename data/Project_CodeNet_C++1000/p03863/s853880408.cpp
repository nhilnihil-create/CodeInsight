#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int ans=0;
	if(s[0]==s[s.size()-1])
	ans=1;
	ans=s.size()%2-ans;
	if(ans)
	cout << "First";
	else
	cout << "Second";
	return 0;
}