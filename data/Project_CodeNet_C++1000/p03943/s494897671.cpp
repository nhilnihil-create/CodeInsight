#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int k=max(max(a,b),c);
  if(k==a+b+c-k)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}