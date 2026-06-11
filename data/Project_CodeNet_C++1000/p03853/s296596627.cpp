#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> gazo(h);
  vector<string> gazo2(h);
  for (int i = 0; i < h; i++) {
    cin >> gazo.at(i);
    gazo2.at(i) = gazo.at(i);
  }
  
  for (int i = 0; i < h; i++) {
    cout << gazo.at(i) << endl;
    cout << gazo2.at(i) << endl;
  }
}