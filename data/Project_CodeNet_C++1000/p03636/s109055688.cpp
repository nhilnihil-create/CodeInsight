#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()


int main(){
  string s;
  cin >> s;
  int n = s.size();
  string t = to_string(n-2);
  string ans = s[0] + t + s[n-1];
  cout << ans << endl;
}
