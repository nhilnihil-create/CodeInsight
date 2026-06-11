//url:
//problem name: 

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

map<ll,ll> mp;

const int MOD = 1000000007;

void prime_factorial(int N) {
    for(int i = 2; i * i <= N; i++) {
        if(N % i == 0) {
            ll ex = 0;
            while(N % i == 0) {
                ex++;
                N /= i;
            }
            if(mp.count(i)) mp[i] += ex;
            else mp[i] = ex;
        }
    }
    if(N != 1) {
        if(mp.count(N)) mp[N]++;
        else mp[N] = 1;
    }
}

int main() {
    ll N; cin >> N;
    for(ll n = 1; n <= N; n++) {
        prime_factorial(n);
    }
    ll ans = 1;
    for(auto p : mp) {
        ans *= p.second+1;
        ans %= MOD;
    }
    cout << ans << endl;
}
