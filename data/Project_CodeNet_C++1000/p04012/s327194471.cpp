#include <bits/stdc++.h>
using namespace std;
int main() {
  string mozi;
  cin >> mozi;
  vector<int> count(26);
  for (int i = 0; i < mozi.size(); i++) {
    if (mozi[i] == 'a') {
      count[0]++;
    }
    if (mozi[i] == 'b') {
      count[1]++;
    }
    if (mozi[i] == 'c') {
      count[2]++;
    }
    if (mozi[i] == 'd') {
      count[3]++;
    }
    if (mozi[i] == 'e') {
      count[4]++;
    }
    if (mozi[i] == 'f') {
      count[5]++;
    }
    if (mozi[i] == 'g') {
      count[6]++;
    }
    if (mozi[i] == 'h') {
      count[7]++;
    }
    if (mozi[i] == 'i') {
      count[8]++;
    }
    if (mozi[i] == 'j') {
      count[9]++;
    }
    if (mozi[i] == 'k') {
      count[10]++;
    }
    if (mozi[i] == 'l') {
      count[11]++;
    }
    if (mozi[i] == 'm') {
      count[12]++;
    }
    if (mozi[i] == 'n') {
      count[13]++;
    }
    if (mozi[i] == 'o') {
      count[14]++;
    }
    if (mozi[i] == 'p') {
      count[15]++;
    }
    if (mozi[i] == 'q') {
      count[16]++;
    }
    if (mozi[i] == 'r') {
      count[17]++;
    }
    if (mozi[i] == 's') {
      count[18]++;
    }
    if (mozi[i] == 't') {
      count[19]++;
    }
    if (mozi[i] == 'u') {
      count[20]++;
    }
    if (mozi[i] == 'v') {
      count[21]++;
    }
    if (mozi[i] == 'w') {
      count[22]++;
    }
    if (mozi[i] == 'x') {
      count[23]++;
    }
    if (mozi[i] == 'y') {
      count[24]++;
    }
    if (mozi[i] == 'z') {
      count[25]++;
    }
  }
  bool ab = true;
  for (int i = 0; i < 26; i++) {
    if (count[i]%2!=0) {
      ab = false;
    }
  }
  if (ab) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}