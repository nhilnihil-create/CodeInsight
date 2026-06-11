#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  string s;
  cin >> s;

  int N = s.length();
  cout << s[0] << N - 2 << s[N - 1] << endl;
}
