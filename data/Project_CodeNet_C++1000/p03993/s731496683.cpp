#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e9;
const long long int mod = 1e9+7;
typedef pair<ll,ll> pairs;
vector<pairs> p;


ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

vector<vector<ll>> combination(ll n, ll r){
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
    for(ll i=0;i<v.size();++i){
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for(ll i=1;i<v.size();++i){
        for(ll j=0;j<i;++j){
            v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]);
        }
    }
    return v;
}
// ------------------------------------

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;++i){
        cin>>a[i];
    }
    ll ans=0;
    for(ll i=0;i<n;++i){
        if(i+1 == a[a[i]-1]){
            ans++;
        }
    }
    ans /= 2;
    cout<<ans<<endl;

    return 0;
}