#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[100001];
  for (int i = 0; i < n; i++) cin >> a[i];
  int divideCount = 1;
  bool incre = false, decre = false;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
      continue;
    } else if (a[i] > a[i + 1]) {  //単調非増加
      decre = true;
    } else if (a[i] < a[i + 1]) {  //単調非減少
      incre = true;
    }
    if (decre && incre) {
      decre = false;
      incre = false;
      divideCount++;
      continue;
    }
  }
  cout << divideCount << endl;
  return 0;
}