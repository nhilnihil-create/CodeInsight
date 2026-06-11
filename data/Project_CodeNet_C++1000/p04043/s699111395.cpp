#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  vector<int> abc(3);
  rep(i, 3) cin >> abc[i];
  sort(abc.begin(), abc.end());
  if(abc[0] == 5 && abc[1] == 5 && abc[2] == 7) cout <<"YES" << endl;
  else cout << "NO" << endl;
}