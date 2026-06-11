#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1001001001001001001;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

int main(){
    ll N;
    cin >> N;
    vector<ll> P(N),A(N),B(N),C(N);
    rep(i,N) cin >> P[i];
    rep(i,N){
        C[P[i]-1] = i+1;
    }
    rep(i,N){
        A[i] = 40000 * (i+1);
        B[i] = 40000 * (N-i-1) + C[i];
    }
    rep(i,N) cout << A[i] << ' ';
    cout << endl;
    rep(i,N) cout << B[i] << ' ';
    cout << endl;
}
