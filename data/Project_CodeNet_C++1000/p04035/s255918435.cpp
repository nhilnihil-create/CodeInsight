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
typedef pair<ll,Pll> Plp;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N,L;
    cin >> N >> L;
    vector<ll> a(N), S(N+1);
    rep(i,N){
        cin >> a[i];
    }
    ll id = 0;
    ll ma = 0;
    rep(i,N-1){
        //if(a[i] + a[i+1] < L){
            //cout << "Impossible" << endl;
            //return 0;
        //}
        if(a[i]+a[i+1] > ma){
            ma = a[i]+a[i+1];
            id = i;
        }
    }
    if(ma < L){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    rep(i,id){
        cout << i+1 << endl;
    }
    for(ll i=N-2;i>id;i--){
        cout << i+1 << endl;
    }
    cout << id+1 << endl;
}