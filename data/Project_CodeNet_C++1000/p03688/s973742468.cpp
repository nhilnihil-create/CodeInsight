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
    vector<ll> a(N);
    ll m = 1e18;
    rep(i,N){
        cin >> a[i];
        cmin(m,a[i]);
    }
    ll M = m + 1;
    ll nofm = 0;
    ll nofM = 0;
    rep(i,N){
        if(a[i] == m){
            nofm++;
        }else if(a[i] == M){
            nofM++;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    if(!nofM){
        if(m == N-1 || m*2 <= N){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
            /*else if(N%m == 0){
            cout << "Yes" << endl;
        }else if(m == 2){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }*/
        return 0;
    }
    if(nofm < M && 2*(M-nofm) <= nofM){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}