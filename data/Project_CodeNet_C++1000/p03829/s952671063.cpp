#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    ll N = in(),A = in(),B = in();
    vector<ll> X(N);
    REP(i,N)X[i] = in();
    ll tired = 0;
    REP(i,N-1){
        tired += min((X[i+1] - X[i]) * A,B);
    }
    cout << tired << "\n";
}