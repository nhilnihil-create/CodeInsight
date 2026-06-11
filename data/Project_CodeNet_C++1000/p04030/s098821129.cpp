#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  string S; cin >> S;
  string ans = "";
    rep(i, (int)S.size()){
      if (S[i] == 'B'){
        if (ans.size() == 0) continue;
        else ans.pop_back();
      }
      else ans += S[i];
    }
  cout << ans <<endl;
  return 0;
}