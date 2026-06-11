#include <bits/stdc++.h>
using namespace std;

#define pb(s) push_back(s)
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L


typedef long long ll;

const ll MOD =1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    map<ll,ll> m;
    for(ll i=1;i<=n;++i){
        ll t=i;
        for(ll j =2;j*j<=t;++j){
            while(t%j==0){
                m[j]++;
                t/=j;
            }
        }
        if(t!=1)m[t]++;
    }

    ll ans=1;
    for(auto u:m) (ans*=(u.second+1))%=MOD;
    cout<<ans;
    return 0;
}
