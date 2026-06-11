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
  int start, end;
  for (int i = 0; i < N; i++){
    if (s[i] == 'A'){
      start = i;
      break;
    }
  }
  for (int i = N - 1; i >= 0; i--){
    if (s[i] == 'Z'){
      end = i;
      break;
    }
  }
  cout << end - start + 1 << endl;
}
