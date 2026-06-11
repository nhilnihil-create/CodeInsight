#include <bits/stdc++.h>
using namespace std;
int main() {
  int H = 0, W = 0;
  cin >> H >> W;
   for (int i = 0; i < W+2; i++) {
     cout << '#';
     if (i == W+1)
       cout << endl;
   }
  vector<char> vec(W);
   for (int i = 0; i < H; i++) {
          cout << '#';
      for (int i = 0; i < W; i++) {
        cin >> vec.at(i);
       cout << vec.at(i);      
      }
          cout << '#' << endl;
   }
  for (int i = 0; i < W+2; i++) {
     cout << '#';
     if (i == W+1)
       cout << endl;
  }
}