#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define yes_or_no(flag) if (flag) { println("Yes"); } else { println("No"); }
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define rsort_vec(vec) sort(vec.rbegin(), vec.rend()) // greater<int>()

int main() {
  // 入力
  int W, H, N;
  cin >> W >> H >> N;

  vector<tuple<int, int, int>> d(N);
  for (int i = 0; i < N; i++) {
    int x, y, a;
    cin >> x >> y >> a;
    d.at(i) = make_tuple(x, y, a);
  }
  
  // 計算
  int xmin = 0;
  int xmax = W;
  int ymin = 0;
  int ymax = H;
  
  for (int i = 0; i < N; i++) {
    int a = get<2>(d.at(i));
    switch (a) {
      case 1: // x < xi
        if (xmin < get<0>(d.at(i)))
          xmin = get<0>(d.at(i));
        break;
      case 2: // x > xi
        if (xmax > get<0>(d.at(i)))
          xmax = get<0>(d.at(i));
        break;
      case 3: // y < yi
        if (ymin < get<1>(d.at(i)))
          ymin = get<1>(d.at(i));
        break;
      case 4: // y > yi
        if (ymax > get<1>(d.at(i)))
          ymax = get<1>(d.at(i));
        break;
    }
  }

  // 出力
  if (xmin > xmax || ymin > ymax) {
	println(0);
  } else {
    println((xmax - xmin) * (ymax - ymin));
  }
}
