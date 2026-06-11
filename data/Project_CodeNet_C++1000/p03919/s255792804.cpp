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

int main(){
  ll H,W; cin >> H >> W;
  REP(i, H) REP(j, W){
    string s;
    cin >> s;
    if(s == "snuke"){
      cout << (char) (j+'A') << i+1 << endl;
    }
  }

}

