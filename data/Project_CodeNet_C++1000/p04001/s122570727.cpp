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
    string s;
    cin>>s;
    ll n = s.size();

    vector<ll> a(n);
    for(ll i=0;i<n;++i){
        a[i] = s[i] - '0';
    }

    ll ans = 0;
    for(ll bit=0;bit<(1<<n-1);++bit){
        ll num = a[0];
        ll sum = 0;
        for(ll i=0;i<n-1;++i){
            if(bit >> i & 1){
                sum += num;
                num = a[i+1];
            }else{
                num *= 10;
                num += a[i+1];
            }
        }
        if(num != a[n-1]){
            sum += num;
        }else{
            sum += a[n-1];
        }
        //cout<<sum<<endl;
        ans += sum;
    }
    cout<<ans<<endl;

    return 0;
}