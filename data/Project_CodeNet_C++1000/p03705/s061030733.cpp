#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
 ll n,a,b;
  cin >> n >> a >> b;
  if((n==1 && a!=b) || a>b){
    cout << 0 << endl;
    return 0;
  }
  cout << (b-a)*(n-2)+1 << endl;
}

