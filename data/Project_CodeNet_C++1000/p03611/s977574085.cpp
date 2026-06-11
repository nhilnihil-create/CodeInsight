#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    ll n;
    cin >> n;
    map<ll,ll> cnt;
    rep(i,0,n){
        ll a;
        cin >> a;
        cnt[a-1]++;
        cnt[a]++;
        cnt[a+1]++;
    }
    ll ans=0;
    rep(i,-1,100010){
        ans=max(ans,cnt[i]);
    }
    cout<<ans<<endl;
  return 0;
}