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
    ll x, y;
    cin>>x>>y;

    ll ans = 0;
    if(x == y){
        ans = 0;
    }else if(x == -y){
        ans += 1;
    }else if(abs(x) > abs(y)){
        ans += abs(x) - abs(y);
        if(x > 0){
            ans++;
        }
        if(y > 0){
            ans++;
        }
    }else{
        ans += abs(abs(x) - abs(y));
        if(x < 0){
            ans++;
        }
        if(y < 0){
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}