#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;

typedef pair<ll, ll> pairs;
typedef vector<pairs> p;

struct Edge{
    ll to, weight;
    Edge(ll t, ll w) : to(t), weight(w){}
};
using graph = vector<vector<ll>>;
using Graph = vector<vector<Edge>>;


ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
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

// 回文
bool kai(string S){
    bool flag = true;
    for(ll i=0;i<S.size()/2;++i){
        if(S[i] != S[S.size()-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
// ---------------------------------------------

int main(){
    ll n, c, k;
    cin>>n>>c>>k;
    vector<ll> t(n);
    for(ll i=0;i<n;++i){
        cin>>t[i];
    }
    sort(t.begin(), t.end());

    ll count = 0;
    ll ans = 0;
    while(count < n){
        ll num = t[count];
        ll sum = 1;
        for(ll i=1;i<c;++i){
            if(count + i >= n){
                break;
            }
            if(t[count + i] - num <= k){
                sum++;
            }else{
                break;
            }
        }
        count += sum;
        ans++;
    }
    cout<<ans<<endl;

    return 0;
}