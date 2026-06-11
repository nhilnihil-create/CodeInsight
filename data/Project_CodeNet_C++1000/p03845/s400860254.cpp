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
  int N,M;
  int T[105]={};
  int P,X;
  int sum = 0;
  int out = 0;
  cin >> N;
  for (int i=1; i <= N; i++) {
    cin >> T[i];
    sum += T[i];
  }
  cin >> M;
  for (int i=1; i <= M; i++) {
    cin >> P >> X;
    out = sum - T[P] + X;
    cout << out << endl;
  }

  return 0;
}
