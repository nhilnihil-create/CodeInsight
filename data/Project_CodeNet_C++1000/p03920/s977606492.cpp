#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
constexpr double EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr int MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;cin>>n;
    vector<ll> sum(100000,0);
    ll idx;
    for(ll i=1;i<=10000;i++){
        sum[i] = sum[i-1]+i;
        if(sum[i]>=n){
            idx=i;
            break;
        }
    }
    for(int i=1;i<=idx;i++){
        if(i==sum[idx]-n) continue;
        cout<<i<<endl;
    }
}
