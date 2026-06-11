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
    ll N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    rep(m,N){
        if(C*(N-1-m)-D*m <= B-A && B-A <= D*(N-1-m) - C*m){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    /*if(B < A - D*(N-1) || A + D*(N-1) < B){
        cout << "NO" << endl;
        return 0;
    }
    if(A-C-D*(N-2) < B && B < A+C-D*(N-2)){
        cout << "NO" << endl;
        return 0;
    }else if(A-C+D*(N-2) < B && B < A+C+D*(N-2)){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;*/

}