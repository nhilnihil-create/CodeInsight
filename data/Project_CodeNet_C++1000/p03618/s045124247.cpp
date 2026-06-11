#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}

int main(){
    ll N;
    string S;
    cin >> S;
    N = S.size();
    vector<ll> c(26);
    rep(i,N){
        c[S[i] - 'a']++;
    }
    ll sum = 0;
    rep(i,26){
        sum += (c[i]*(c[i]-1))/2;
    }
    ll ans = 1 + N*(N-1)/2 - sum;
    cout << ans << endl;
}