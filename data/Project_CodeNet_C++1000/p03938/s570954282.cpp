#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N;
    cin >> N;
    vector<ll> p(N),a(N),b(N);
    rep(i,N){
        cin >> p[i];
        p[i]--;
    }
    rep(i,N){
        a[i] = (i+1)*30000;
    }
    //b[p[0]] = 1e5;
    REP(i,0,N){
        b[N-1-i] = 30000*(i+1);
    }
    rep(i,N){
        b[p[i]] += i+1;
    }
    PR(a,N);
    PR(b,N);
}