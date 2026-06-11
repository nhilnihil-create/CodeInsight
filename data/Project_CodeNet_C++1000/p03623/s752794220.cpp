#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  int x,a,b;
  cin >> x >> a >> b;
  if(abs(x-a)>abs(x-b))
    cout << "B" << endl;
  else
    cout << "A" << endl;
}