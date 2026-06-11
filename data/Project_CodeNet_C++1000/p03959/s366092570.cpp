#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1000000007;
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
    vector<ll> T(N), A(N), S(N), SS(N);
    rep(i,N) cin >> T[i];
    rep(i,N) cin >> A[i];
    ll cur = 0;
    rep(i,N){
        if(cur < T[i]){
            cur = T[i];
            S[i] = cur;
        }
    }
    cur = 0;
    rep(i,N){
        if(cur < A[N-1-i]){
            cur = A[N-1-i];
            SS[N-1-i] = cur;
        }
    }
    rep(i,N){
        if(S[i] > 0 && SS[i] > 0){
            if(S[i] != SS[i]){
                cout << 0 << endl;
                return 0;
            }
        }else if(S[i] > 0 && SS[i] == 0){
            if(!(T[i] <= A[i])){
                cout << 0 << endl;
                return 0;
            }
        }else if(S[i] == 0 && SS[i] > 0){
            if(!(A[i] <= T[i])){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    /*if(T[N-1] != A[0]){
        cout << 0 << endl;
        return 0;
    }*/
    ll ans = 1;
    rep(i,N){
        if(S[i] > 0 || SS[i] > 0){
            continue;
        }else{
            ans *= min(T[i],A[i]);
            ans %= mo;
        }
    }
    cout << ans << endl;
}