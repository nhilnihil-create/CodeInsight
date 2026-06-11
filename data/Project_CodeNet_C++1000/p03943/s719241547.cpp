#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
int main() {
  int d[3]; for (int i =0; i<3; i++) cin >> d[i];
  sort(d,d+3);
  
  if (d[0] + d[1] == d[2]) cout << "Yes" << endl;
  else cout << "No" << endl;
}