#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define MOD 1000000007
int N;
int X[100000];
map<int, bool> b;

int main() {
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> X[i];
  }
  long long s = 1;
  int l = 0;
  for (int k=0; k<N; k++) {
    long long a = N-k;
    for (; l<N-k; l++) {
      if (l*2+1 <= X[l+k]) {
      }
      else {
        a = l+1;
        break;
      }
    }
    s = (s*a) % MOD;
  }
  cout << s <<"\n";
  return 0;
}
