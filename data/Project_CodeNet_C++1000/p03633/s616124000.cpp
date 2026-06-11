#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define FOR(i, m, n) for(ll i = m; i < (n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>; 
using vl = vector<ll>;
using vll = vector<vl>;
using pll = pair<ll, ll>;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b,a % b); 
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main() {
    ll N;
    cin >> N;
    vl T(N);
    rep(i, N){
        cin >> T[i];
    }

    ll a;
    ll tmp;
    if(N == 1){
        cout << T[0] << endl;
        return 0;
    }

    rep(i, N-1){
        if(i == 0){
            a = lcm(T[i], T[i+1]);
        }else{
            a = lcm(tmp, T[i+1]);
        }
        tmp = a;
    }
    cout << a << endl;
}