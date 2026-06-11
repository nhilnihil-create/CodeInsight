#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  string border(W + 2, '#');
  
  vector<string> a(H + 2);

  a[H + 1] = a[0] = border;
  for (int i = 1; i < (H + 1); i++) {
	cin >> a[i];
    a[i] = "#" + a[i] + "#";
  }

  // 出力
   for (auto itr = a.begin(); itr != a.end(); ++itr) {
        cout << *itr << endl;
   }
}
