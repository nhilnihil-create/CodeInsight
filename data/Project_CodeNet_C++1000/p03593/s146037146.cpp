#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int h, w;
  cin >> h >> w;
  
  vector<int> x(26);
  for (int i = 0; i < h * w; i++) {
    char a;
    cin >> a;
    x.at(a - 'a')++;
  }
  
  if (h % 2 == 0 && w % 2 == 0) {
    for (int i = 0; i < 26; i++) {
      if (x.at(i) % 4 != 0) {
        cout << "No\n";
        return 0;
      }
    }
    cout << "Yes\n";
    return 0;
  }
  else if (h % 2 == 1 && w % 2 == 1) {
    bool flag = false;
    for (int i = 0; i < 26; i++) {
      if (x.at(i) % 2 == 1) {
        if (flag) {
          cout << "No\n";
          return 0;
        }
        else {
          x.at(i)--;
          flag = true;
        }
      }
    }
    int count4 = 0;
    for (int i = 0; i < 26; i++) {
      if (x.at(i) >= 4) {
        count4 += x.at(i) / 4;
        x.at(i) %= 4;
      }
    }
    int count2 = 0;
    for (int i = 0; i < 26; i++) {
      if (x.at(i) >= 2) {
        count2 += x.at(i) / 2;
        x.at(i) %= 2;
      }
    }
    if (count4 >= (h / 2) * (w / 2)) {
      count4 -= (h / 2) * (w / 2);
      if (count4 * 2 + count2 >= (h / 2) + (w / 2)) {
        cout << "Yes\n";
        return 0;
      }
      else {
        cout << "No\n";
        return 0;
      }
    }
    else {
      cout << "No\n";
      return 0;
    }
  }
  else {
    int count4 = 0;
    for (int i = 0; i < 26; i++) {
      if (x.at(i) >= 4) {
        count4 += x.at(i) / 4;
        x.at(i) %= 4;
      }
    }
    int count2 = 0;
    for (int i = 0; i < 26; i++) {
      if (x.at(i) >= 2) {
        count2 += x.at(i) / 2;
        x.at(i) %= 2;
      }
    }
    if (count4 >= (h / 2) * (w / 2)) {
      count4 -= (h / 2) * (w / 2);
      if (count4 * 2 + count2 >= (h / 2) * (w % 2) + (w / 2) * (h % 2)) {
        cout << "Yes\n";
        return 0;
      }
      else {
        cout << "No\n";
        return 0;
      }
    }
    else {
      cout << "No\n";
      return 0;
    }
  }
}