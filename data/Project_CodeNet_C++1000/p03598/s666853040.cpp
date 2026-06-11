#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define repi(i,n) for(int i=0; i<(n); i++)

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> p(N);
  repi(i,N) cin >> p.at(i);
  //ボール探索
  int routelen=0;
  repi(i,N) {
    if (p.at(i)<K-p.at(i)) routelen += p.at(i);
    else routelen += K-p.at(i);
  }
  cout << routelen*2 << endl;
}