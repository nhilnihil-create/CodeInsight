#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;
typedef long long ll;

int main() {
  int K,S;
  cin >> K >> S;
  int cnt=0;
  for (int X=0; X <= K; X++) {
    for (int Y=0; Y <= K; Y++) {
      int Z = S - Y -X;
      if (0 <= Z && Z <=K) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
