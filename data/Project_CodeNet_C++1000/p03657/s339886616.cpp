#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  int a,b;
  cin >> a >> b;
  int c=a+b;
  if(a%3==0||b%3==0||c%3==0)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
}