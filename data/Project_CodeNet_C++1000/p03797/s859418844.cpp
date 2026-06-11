#include <bits/stdc++.h>
using namespace std;

int main() {
  long long S,C;
  cin >> S >> C;
  if(S * 2 >= C)cout << C/2 <<endl;
  else{
    cout << S+(C-2*S)/4 <<endl;
  }
}