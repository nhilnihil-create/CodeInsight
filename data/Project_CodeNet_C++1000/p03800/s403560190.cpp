#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main()
{
	int n;
	cin >> n;
	string s;cin >> s;
	for(int S = 0;S<2 ;++S)
	{
		for(int W = 0;W < 2;W++)
		{
			string ans;
			if(S==0&&W==0)ans="SS";
			if(S==1&&W==0)ans="WS";
			if(S==0&&W==1)ans="SW";
			if(S==1&&W==1)ans="WW";

			for(int i=1;i<n-1;i++)
			{
				if(s[i]=='o'&&ans[i]=='S')
				{
					ans.push_back(ans[i-1]);
				}
				if(s[i]=='o'&&ans[i]=='W')
				{
					ans.push_back(ans[i-1]=='S'?'W':'S');
				}
				if(s[i]=='x'&&ans[i]=='S')
				{
					ans.push_back(ans[i-1]=='S'?'W':'S');
				}
				if(s[i]=='x'&&ans[i]=='W')
				{
					ans.push_back(ans[i-1]);
				}
			}
			bool isans = true;
			if(ans[0]=='S')
			{
				if(s[0]=='o'&&ans[1]!=ans[n-1])isans=false;
				if(s[0]=='x'&&ans[1]==ans[n-1])isans=false;
			}
			if(ans.back()=='S')
			{
				if(s.back()=='o'&&ans[0]!=ans[n-2])isans=false;
				if(s.back()=='x'&&ans[0]==ans[n-2])isans=false;
			}
			if(ans[0]=='W')
			{
				if(s[0]=='o'&&ans[1]==ans[n-1])isans=false;
				if(s[0]=='x'&&ans[1]!=ans[n-1])isans=false;
			}
			if(ans.back()=='W')
			{
				if(s.back()=='o'&&ans[0]==ans[n-2])isans=false;
				if(s.back()=='x'&&ans[0]!=ans[n-2])isans=false;
			}
			if(isans)
			{
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}