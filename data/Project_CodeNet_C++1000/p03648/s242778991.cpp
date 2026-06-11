#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli>> mat;

lli k;
lli n = 50;
vll a;

int main(){
  cin >> k;
  a = vll(n,n-1 + k/n);
  for(lli i = 0;i < k%n;i++){
    a[i]++;
  }
  for(lli i = k%n;i < n;i++){
    a[i] -= k%n;
  }
  cout << n << endl;
  cout << a[0];
  for(lli i = 1;i < n;i++){
    cout << " " << a[i];
  }
  cout << endl;
  return 0;
}
