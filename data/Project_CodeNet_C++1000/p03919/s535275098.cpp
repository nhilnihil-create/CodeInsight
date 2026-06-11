#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<string>> S(H, vector<string>(W));
  for (int i=0; i<H; i++)
    for (int j=0; j<W; j++)
      cin >> S.at(i).at(j);
  
  for (int i=0; i<H; i++)
    for(int j=0; j<W; j++)
      if (S.at(i).at(j) == "snuke")
        cout << (char)('A'+j) << i+1 << endl;
}