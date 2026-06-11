#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;



//WBWBWB -> WBWBWWW -> WBWBBBB -> WBWWWWWW -> WBBBBBBB -> BBBB///
int main(){
  string s;
  cin >> s;

  int n = sz(s);

  int ans = 0;
  rep(i,n-1){
    if(s[i] != s[i+1]) ans++;
  }
  cout << ans << endl;
}
