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

vector<vector<ll>> d(301,vector<ll>(301,1e18)); 
void warshall_floyd(int n) { // nは頂点数
  for (int i = 0; i < n; i++)      // 経由する頂点
    for (int j = 0; j < n; j++)    // 開始頂点
      for (int k = 0; k < n; k++)  // 終端
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> A(N,vector<ll>(N));
    rep(i,N){
        rep(j,N){
            cin >> A[i][j];
            d[i][j] = A[i][j];
        }
    }
    warshall_floyd(N);
    rep(i,N){
        rep(j,N){
            if(d[i][j] != A[i][j]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    ll ans = 0;
    rep(i,N){
        REP(j,i+1,N){
            ans += d[i][j];
        }
    }
    rep(i,N){
        REP(j,i+1,N){
            rep(k,N){
                if(i == j) continue;
                if(j == k) continue;
                if(k == i) continue;
                if(d[i][j] == d[i][k] + d[k][j]){
                    ans -= d[i][j];
                    break;
                } 
            }
        }
    }
    cout << ans << endl;
}