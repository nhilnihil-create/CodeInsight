#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(9, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a < 400)
      ++vec[0];
    else if (a < 800)
      ++vec[1];
    else if (a < 1200)
      ++vec[2];
    else if (a < 1600)
      ++vec[3];
    else if (a < 2000)
      ++vec[4];
    else if (a < 2400)
      ++vec[5];
    else if (a < 2800)
      ++vec[6];
    else if (a < 3200)
      ++vec[7];
    else
      ++vec[8];
  }

  int cnt = 0;
  for (int i = 0; i < 8; ++i)
    cnt += vec[i] != 0;

  int vmin = cnt != 0 ? cnt : 1;
  int vmax = cnt + vec[8];
  cout << vmin << " " << vmax << endl;
}
