#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n;
  cin >> n;
  vint T(n);
  vint A(n);
  rep(i,0,n) cin >> T[i];
  rep(i,0,n) cin >> A[i];
  vbool Tjudge(n);
  vbool Ajudge(n);
  rep(i,1,n){
    if(T[i] == T[i-1]) Tjudge[i] = true;
  }
  rrep(i,n-2,0){
    if(A[i] == A[i+1]) Ajudge[i] = true;
  }
  int ans = 1;
  rep(i,0,n){
    if(Tjudge[i] && Ajudge[i]){
      ans *= min(T[i],A[i]);
      ans %= MOD;
    }
    if(!(Tjudge[i]) && Ajudge[i]){
      if(T[i] > A[i]){
        cout << 0 << endl;
        return 0;
      }
    }
    if(Tjudge[i] && !(Ajudge[i])){
      if(A[i] > T[i]){
        cout << 0 << endl;
        return 0;
      }
    }
    if(!(Tjudge[i]) && !(Ajudge[i])){
      if(T[i] != A[i]){
        cout << 0 << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
}