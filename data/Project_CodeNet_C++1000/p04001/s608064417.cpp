#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define re return
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
signed main()
{
	string s;
	cin>>s;
	reverse(all(s));
	int ans=0;
	for (int mask=0;mask<(1<<(sz(s)-1));mask++){
		int x=s[0]-'0';
		int num=1;
		for (int i=1;i<sz(s);i++){
			num*=10;
			if ((mask>>(i-1))&1){
				num=1;
			}
			x+=((s[i]-'0')*num);
		}
		ans+=x;//cout<<x<<'+';
	}
	cout<<ans;
	re 0;
}
