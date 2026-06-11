#include <bits/stdc++.h>
using namespace std;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  
  cout << "L";
  
  for (int i=0; i<ty+1-sy; i++)
    cout << "U";
  for (int i=0; i<tx-sx+1; i++)
    cout << "R";
  for (int i=0; i<ty+1-sy; i++)
    cout << "D";
  for (int i=0; i<tx-sx; i++)
    cout << "L";
  for (int i=0; i<ty-sy; i++)
    cout << "U";
  for (int i=0; i<tx-sx+1; i++)
    cout << "R";
  for (int i=0; i<ty-sy+1; i++)
    cout << "D";
  for (int i=0; i<tx-sx+1; i++)
    cout << "L";
  cout << "U";

  return 0;
}