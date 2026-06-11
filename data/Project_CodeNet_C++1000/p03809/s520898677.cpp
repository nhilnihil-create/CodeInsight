//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod=1e8+7;
const int MAXN=1e5+9;
const double eps=1e-8;
const long double pi=3.1415926535897932384626433832795;
const long double e=2.71828182845904523536028747135266;
ll n,c[MAXN];
vector<ll> E[MAXN];
ll dfs(ll x,ll fr)
{
	if(E[x].size()==1) {
        return c[x];
    }
	ll s=0,mx=0,w;
	for(auto R:E[x]) {
        if(R!=fr) w=dfs(R,x),mx=max(mx,w),s+=w;
    }
	mx*2<=s?mx=s/2:mx=s-mx;
	if(c[x]>s||c[x]<s-mx) {
        cout << "NO" << endl;
        exit(0);
    }
	w=s-c[x];w=s-2*w;
	if(w<0) {
        cout << "NO" << endl;
        exit(0);
    }
	return w;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    while(t--){
        cin>>n;for(ll i=1;i<=n;i++) cin>>c[i];
	    if(n==2) {
            if(c[1]==c[2]) cout << "YES" << endl;
            else {
                cout << "NO" << endl;
            }
            return 0;
        }
	    for(ll i=1,x,y;i<n;i++) {
            cin>>x>>y;
            E[x].push_back(y);
            E[y].push_back(x);
        }
	    for(ll i=1;i<=n;i++) {
            if(E[i].size()>1) {
                if(dfs(i,0)) cout << "NO" << endl;
                else {
                    cout << "YES" << endl;
                    
                }
                exit(0);
            }
        }
    }
    return 0;
}

