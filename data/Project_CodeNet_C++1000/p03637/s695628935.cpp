#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int count0 = 0, count2 = 0, count4 = 0;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;

    if (!(num % 4)) {
      count4++;
    } else if (!(num % 2)) {
      count2++;
    } else {
      count0++;
    }
  }

  // 4が半分以上あれば、すべて4の倍数となる
  if (count4 >= N / 2) {
    cout << "Yes" << endl;
    return 0;
  }

  // 4の数が0の数以上であれば、4の倍数とできる
  // 仮に2が1つだけあった場合も末尾に移動することで4の倍数となる(1,4,1,4,2)
  if (count4 >= count0) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
}