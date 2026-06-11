#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int INF = 2e9;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  int l = 0;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') cnt++;
    else {
      if (cnt == 0) l++;
      else cnt--;
    }
  }

  int r = cnt;
  string res = "";
  for (int i = 0; i < l; i++) res += '(';
  res += s;
  for (int i = 0; i < r; i++) res += ')';
  cout << res << endl;
  return 0;
}