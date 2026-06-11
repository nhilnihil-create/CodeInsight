#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
//  cout << N << endl;
  
  vector<int> a(N+1);
  for(int i=1; i<N+1; ++i) {
    cin >> a.at(i);
//    cout << a.at(i) << endl;
  }

  int tmp = 1, cnt = 1, result = -1;
  while (1) {
    int tmp_cnt = tmp;
    tmp = a.at(tmp_cnt);
    a.at(tmp_cnt) = 1; // ループを検出
    if (tmp == 2) {
      result = cnt;
      break;
    } else if (tmp == 1) {
      result = -1;
      break;
    } else {
    }
    ++cnt;
  }
  
  cout << result << endl;

  return 0;
}