#include <bits/stdc++.h>
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP2(i, a, b) for(int i = a;i <= b;i++)
#define REPR(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define PI 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define vi2 vector<vector<int>>
#define eb emplace_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
using P = pair<ll,ll>;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};
#define INT(name) int name;cin >> name;
#define VEC(type,name,n) vector<type> name(n);REP(i,n) cin >> name[i];

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  INT(N);
  INT(M);
  INT(R);
  vector<int> r(R);
  REP(i, R){
    cin >> r[i];
    r[i]--;
  }
  sort(ALL(r));
  vector<vector<ll>> A(M,vector<ll>(3));
  vector<vector<ll>> List(N,vector<ll>(N,INF));
  REP(i,N){
    REP(j,N){
      if(i==j){
        List[i][j]=0;
      }
    }
  }
  REP(i, M){
    REP(j, 3){
      cin >> A.at(i).at(j);
    }
    A.at(i).at(0)--;
    A.at(i).at(1)--;
    List[A[i][0]][A[i][1]]=A[i][2];
    List[A[i][1]][A[i][0]]=A[i][2];
  }
  REP(i,N){
    REP(j,N){
      REP(k,N){
        chmin(List[j][k],List[j][i]+List[i][k]);
      }
    }
  }

  // REP(i,N){
  //   REP(j,N){
  //     cout << List[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  ll ans=INF;
  do{
    ll cnt = 0;
    REP(i,R-1){
      cnt+=List[r[i]][r[i+1]];
    }
    chmin(ans,cnt);
  }while(next_permutation(ALL(r)));
  
  cout << ans << endl;
}