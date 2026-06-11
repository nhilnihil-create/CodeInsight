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
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;++i){
        cin>>a[i];
    }

    ll ans = 1;
    ll flag = 0;
    for(ll i=1;i<n;++i){
        if(flag == 0){
            if(a[i-1] > a[i]){
                flag = 1;
            }else if(a[i-1] == a[i]){
                flag = 0;
            }else if(a[i-1] < a[i]){
                flag = 3;
            }
        }else if(flag == 1){
            if(a[i-1] >= a[i]){
                continue;
            }else{
                ans++;
                flag = 0;
            }
        }else if(flag == 3){
            if(a[i-1] > a[i]){
                ans++;
                flag = 0;
            }else{
                continue;
            }
        }
    }
    cout<<ans<<endl;
}