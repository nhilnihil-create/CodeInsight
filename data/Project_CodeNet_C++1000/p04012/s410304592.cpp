#include <bits/stdc++.h>
using namespace std;
int main() {
  string w;
  cin >> w;
  vector<int>W(w.size());
  vector<int>count(26,0);
  for (int i = 0; i < w.size(); i++) {
    W.at(i) = w.at(i) - '0';
    W.at(i) -= 49;
    count.at(W.at(i))++;
  }
  for (int i = 0; i < 26; i++) {
    if (count.at(i) % 2 == 1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
  