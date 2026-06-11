#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string O, E;
  cin >> O >> E;

  for (int i = 0; i < O.size(); i++)
  {
    cout << O.at(i);

    if (O.size() - E.size() == 1 && i == O.size() - 1) break;

    cout << E.at(i);
  }
  cout << "" << endl;
}