#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n; cin >> n;
  vector<bool> colors(8);
  for (int i=0; i<8; i++) colors[i] = false;
  int min=0, max=0, pro=0;

  for (int i=0; i<n; i++) {
    int a; cin >> a;
    for (int j=0; j<8; j++) {
      if (a >= j*400 && a < (j+1)*400) {
        colors[j] = true;
        break;
      }
      else if (a >= 3200) {
        pro++;
        break;
      }
    }
  }
  for (int i=0; i<8; i++) 
    if (colors[i]) min++;
  max = min + pro;
  if (min == 0) min=1;
  cout << min << " " << max << endl;
  return 0;
}