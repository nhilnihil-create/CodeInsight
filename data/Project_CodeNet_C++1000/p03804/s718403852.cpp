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
    ll N,M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,M){
        cin >> B[i];
    }
    rep(i,N-M+1){
        rep(j,N-M+1){
            bool flag = 0;
            rep(h,M){
                rep(w,M){
                    if(B[h][w] == A[h+i][w+j]){
                        continue;
                    }else{
                        flag = 1;
                        goto gt;
                    }
                }
            }
            gt:
            if(!flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}