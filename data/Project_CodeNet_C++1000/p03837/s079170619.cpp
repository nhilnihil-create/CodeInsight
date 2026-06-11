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

vector<vector<ll>> d(100,vector<ll>(100,1e18));

void warshall_floyd(int n) { // nは頂点数
  for (int i = 0; i < n; i++)      // 経由する頂点
    for (int j = 0; j < n; j++)    // 開始頂点
      for (int k = 0; k < n; k++)  // 終端
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> A(M), B(M), C(M);
    rep(i,M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
        d[A[i]][B[i]] = C[i];
        d[B[i]][A[i]] = C[i];
    }
    rep(i,N){
        d[i][i] = 0;
    }
    warshall_floyd(N);
    ll ans = 0;
    rep(i,M){
        bool flag = false;
        rep(j,N){
            rep(k,N){
                if(d[j][A[i]] + C[i] + d[B[i]][k] == d[j][k]){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) ans++;
    }
    cout << ans << endl;
}