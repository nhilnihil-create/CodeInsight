#include <iostream>
using namespace std;

int main() {
  long long Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  N *= 4;
  long long count = 0;
  if (D < 2 * S && D < 4 * H && D < 8 * Q){
    count += (N / 8) * D;
    N %= 8;
  }
  if (S < 2 * H && S < 4 * Q){
    count += (N / 4) * S;
    N %= 4;
  }
  if (H < 2 * Q){
    count += (N / 2) * H;
    N %= 2;
  }
  count += N * Q;
  
  cout << count << endl;
}