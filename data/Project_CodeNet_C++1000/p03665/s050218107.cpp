#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
  ll N, P;
  cin >> N >> P;
  bool flag = true;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a%2==1) flag = false;
  }
  if (flag&&P==1) cout << 0 << endl;
  if (flag&&P==0) cout << (long long)pow(2, N) << endl;
  if (!flag) cout << (long long)pow(2, N-1) << endl;
}