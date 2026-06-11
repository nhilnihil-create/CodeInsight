#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=1e9+7;
const int mod=998244353;
int main(){
    ll n;cin>>n;
    ll ans=0;
    ll ma=0;
    rep(i,n){
        ll a;cin>>a;
        if(ma+1==a){
            ma=a;
            continue;
        }else{
            ans+=(a-1)/(ma+1);
            ma=max(ma,1LL);
        }
    }
    cout<<ans<<endl;
}