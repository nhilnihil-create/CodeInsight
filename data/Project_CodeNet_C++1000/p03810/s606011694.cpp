#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb(x) push_back(x)
#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> point;

int n;

void solve(vector <int> &v, bool flip = false){
  int mod[2] = {0, 0};
  REP(i, n)
    mod[ v[i] % 2 ] ++;

  if(mod[0] % 2){
    cout << (flip ? "Second" : "First");
    return;
  }
  if(mod[0] % 2 == 0 && mod[1] >= 2){
    cout << (flip ? "First" : "Second");
    return;
  }
  int gcd = 0;

  REP(i, sz(v)){
    if(v[i] % 2){
      v[i] --;
      if(v[i] == 0){
        cout << (flip ? "First" : "Second");
        return;
      }
      gcd = __gcd(gcd, v[i]);
    }
    else
      gcd = __gcd(gcd, v[i]);
  }
  REP(i, sz(v))
    v[i] /= gcd;

  solve(v, !flip);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  vector <int> v;
  cin >> n;
  v.resize(n);

  REP(i, n)
    cin >> v[i];
  solve(v);
}

