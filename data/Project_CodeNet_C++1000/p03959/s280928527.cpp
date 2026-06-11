#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N;
    cin >> N;
    vector<ll> T(N), A(N);
    rep(i,N){
        cin >> T[i];
    }
    rep(i,N){
        cin >> A[i];
    }
    vector<ll> VT(N), VA(N);
    ll hst = 0;
    rep(i,N){
        if(hst < T[i]){
            VT[i] = 1;
            hst = T[i];
        }
    }
    hst = 0;
    rep(i,N){
        if(hst < A[N-1-i]){
            VA[N-1-i] = 1;
            hst = A[N-1-i];
        }
    }
    ll ans = 1;
    rep(i,N){
        //cout << i << endl;
        if(VT[i]==1 && VA[i]==1){
            if(T[i] == A[i]){
                continue;
            }else{
                cout << 0 << endl;
                return 0;
            }
        }else if(VT[i]){
            if(T[i] > A[i]){
                cout << 0 << endl;
                return 0;
            }else{
                continue;
            }
        }else if(VA[i]){
            if(A[i] > T[i]){
                cout << 0 << endl;
                return 0;
            }else{
                continue;
            }
        }else{
            ans *= min(T[i], A[i]);
            ans %= mo;
        }
    }
    cout << ans << endl;
}