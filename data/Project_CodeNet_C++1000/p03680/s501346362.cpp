#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> a(N);
 
  for (int i = 0; i < N; i++) {
    cin >> a[i];  
  }
  
  int count = 0;
  int pos = 0;
  while(true) {
  	int next = a[pos] - 1;
    // 一度行ったところはマークする
    a[pos] = 0;
    // ボタンを押した回数
    count++;

    // 一度来た所に来てしまった
    if (next < 0) {
      cout << -1 << endl;
      return 0;
    }
    
    // 2のボタンが次
    if (next == 1) {
		break;
    }
    
    pos = next;
  }
  cout << count << endl;
}
