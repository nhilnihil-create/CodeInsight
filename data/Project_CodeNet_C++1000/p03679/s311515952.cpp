#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
  int x,a,b;
  cin >> x >> a >> b;
  
  if (b <= a)
    cout << "delicious" << endl;
  if (a+1 <= b && b <= a+x)
    cout << "safe" << endl;
  if (a+x+1 <= b)
    cout << "dangerous" << endl;
}