#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
    int n;cin>>n;
    int l[2*n];REP(i,2*n)cin>>l[i];
    sort(l,l+n*2);
    int sum=0;
    REP(i,n)sum+=min(l[i*2],l[i*2+1]);
    cout<<sum<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}