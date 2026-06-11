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
  //0,1番を元にして2,3,...,N-1番を埋める
  FOR(i,1,N-1){
    if(ans[i] == 0 && s[i]=='o' || ans[i] == 1 && s[i] == 'x'){
      ans[i+1] = ans[i-1];
    }else ans[i+1] = !ans[i-1];
  }
  //s[0], s[N-1]の仮定を満たしているか確認
  bool f = true;
  REP(i,2){
    ll l = (N-2+i)%N;
    ll m = (l+1)%N;
    ll r = (m+1)%N;
    if(ans[m] == 0 && s[m] == 'o' && ans[l] != ans[r]) f = false;
    if(ans[m] == 0 && s[m] =='x' && ans[l] == ans[r]) f =  false;
    if(ans[m] == 1 && s[m] == 'o' && ans[l] == ans[r]) f =  false;
    if(ans[m] == 1 && s[m] =='x' && ans[l] != ans[r]) f =  false;
  }
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

  REP(i,4){
    vector<int> ans(N,-1);
    ans[0] = i%2;
    ans[1] = i/2;
    check(s,ans,N);
  }
  cout << -1 << endl;
}