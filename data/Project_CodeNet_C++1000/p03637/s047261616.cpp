#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;

  // 2で割り切れない数の個数
  int count1 = 0;

  // 4で割り切れる数の個数
  int count2 = 0;

  // 4で割り切れないが2で割り切れる数の個数
  int count3 = 0;

  for (int i = 0; i < N; i++){
    int a;
    cin >> a;
    if (a % 2 != 0) {
      count1++;
    } else if (a % 4 == 0) {
      count2++;
    } else {
      count3++;
    }
  }
  
  string answer = "No";

  if (count3 == 0) {
    if (count1 <= count2 + 1) {
      answer = "Yes";
    }
  } else {
    if (count1 <= count2) {
      answer = "Yes";
    }
  }

  cout << answer << endl;

  return 0;

}