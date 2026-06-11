#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int an[3];rep(i,3)cin>>an[i];
  sort(an, an+3);
  int c=3;
  if (an[0]==an[1])c--;
  if (an[1]==an[2])c--;
  cout << c;
}
