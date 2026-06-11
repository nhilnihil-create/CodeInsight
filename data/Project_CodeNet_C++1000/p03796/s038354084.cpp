#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
long long const md = 1000000007;

ll factorial(ll a){
  if ( a == 0 )
    return 1;
  else
    return factorial(a-1) * a % md;
}

int main() {
  long long n;
  cin >> n;
  cout << factorial(n) << endl;
}