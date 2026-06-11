#include <bits/stdc++.h>
using namespace std;

long long f(int a, int b){

  long long mn = 1LL<<60;

  // 1辺を固定して考える
  for (int i = 0; i < a; i++) {

    int side1 = i;
    int side2 = (a - i) / 2;

    long long areaA = (long long) i * b;

    long long areaB = (long long) side2 * b;
    long long areaC = (long long) (a - i - side2) * b;

    long long min_ = min(areaA, min(areaB, areaC));
    long long max_ = max(areaA, max(areaB, areaC));

    mn = min(max_ - min_, mn);

    int side3 = b / 2;

    long long areaD = (long long) (a - i) * side3;
    long long areaE = (long long) (a - i) * (b - side3);

    min_ = min(areaA, min(areaD, areaE));
    max_ = max(areaA, max(areaD, areaE));

    mn = min(max_ - min_, mn);

  }

  return mn;

}

int main() {

  int H, W;
  cin >> H >> W;

  long long answer = min(f(H, W), f(W, H));
  
  cout << answer << endl;

  return 0;

}