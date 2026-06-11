#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define ld long double
#define vi vector<vector<ll> >
using namespace std;
const int MOD=1000000007;
const int MOD2=998244353;
const ll MAX=9187201950435737471;
const int N=100005;
const int INF=1e9+7;
const long double PI=acos(-1);



void solve(int T){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<"0\n";
        return;
    }
    sort(a.begin(),a.end());
    ll ans=MAX;
    for(int i=a[0];i<=a[n-1];i++){
        ll md=i;
        ll tmp=0;
        for(int i=0;i<n;i++){
            tmp+=abs(a[i]-md)*abs(a[i]-md);
            //cout<<ans<<" ";
        }
        ans=min(tmp,ans);
    }
    //cout<<md<<"\n";

    cout<<ans<<"\n";
}

int main() {
    fastio

    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
	return 0;
}
