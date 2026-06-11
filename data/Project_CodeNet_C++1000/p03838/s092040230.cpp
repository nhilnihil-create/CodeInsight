#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
	int x,y;cin>>x>>y;
	cout<<abs(abs(x)-abs(y))+((x<0&&y<0)||(x>=0&&y>=0)?(x>=y)*2:1)+(y?0:-1)<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}