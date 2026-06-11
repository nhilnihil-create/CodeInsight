#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll N,K;
    cin >> N >> K;
    map<ll,ll> mp;
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        mp[a]+=b;
    }
    rep(i,100100){
        if(mp[i]>=K){
            cout << i << endl;
            return 0;
        }else{
            K-=mp[i];
        }
    }
    return 0;
}