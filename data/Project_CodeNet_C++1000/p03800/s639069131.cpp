#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

string t = "SW";
void check(const string& s, vector<int>& ans, ll N){
  FOR(i,1,N-1){
    if(ans[i] == 0 && s[i]=='o' || ans[i] == 1 && s[i] == 'x'){
      if(ans[(N+i+1)%N] == -1) ans[(N+i+1)%N] = ans[i-1];
      else if(ans[(N+i+1)%N] != ans[i-1]) return;
    }else{
      if(ans[(N+i+1)%N] == -1 )ans[(N+i+1)%N] = !ans[i-1];
      else if(ans[(N+i+1)%N] == ans[i-1]) return;
    }
  }
  bool f = false;
  if(ans[N-1] == 0 && s[N-1] == 'o' && ans[N-2] == ans[0]) f = true;
  if(ans[N-1] == 0 && s[N-1] =='x' && ans[N-2] != ans[0]) f =  true;
  if(ans[N-1] == 1 && s[N-1] == 'o' && ans[N-2] != ans[0]) f =  true;
  if(ans[N-1] == 1 && s[N-1] =='x' && ans[N-2] == ans[0]) f =  true;
  if(!f) return;

  REP(i,N){
    cout << t[ans[i]];
  }
  cout << endl;
  exit(0);
}

int main(){
  ll N; cin >> N;
  string s; cin >> s;
  if(s[0]=='o'){
    REP(i,4){//0番が羊と仮定
      vector<int> ans(N,-1);
      if(i==0){//両隣が羊
        ans[0] = 0;
        ans[N-1] = 0;
        ans[1] = 0;
      }else if(i==1){//両隣が狼
        ans[0] = 0;
        ans[N-1] = 1;
        ans[1] = 1;
      }else if(i==2){//0版が狼と仮定
        ans[0] = 1;
        ans[N-1] = 0;
        ans[1] = 1;
      }else{
        ans[0] = 1;
        ans[N-1] = 1;
        ans[1] = 0;
      }
      check(s,ans,N);
    }
  }else{
    REP(i,4){//0番が狼と仮定
      vector<int> ans(N,-1);
      if(i==0){//両隣が羊
        ans[0] = 1;
        ans[N-1] = 0;
        ans[1] = 0;
      }else if(i==1){//両隣が狼
        ans[0] = 1;
        ans[N-1] = 1;
        ans[1] = 1;
      }else if(i==2){//0版が羊と仮定
        ans[0] = 0;
        ans[N-1] = 0;
        ans[1] = 1;
      }else{
        ans[0] = 0;
        ans[N-1] = 1;
        ans[1] = 0;
      }
      check(s,ans,N);
    }
  }
  cout << -1 << endl;
}

