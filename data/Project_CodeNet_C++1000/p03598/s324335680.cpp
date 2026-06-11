#include<bits/stdc++.h>
using namespace std;

int main() {
  int n,k; cin >> n >> k;

  int x,a,b;
  int sum = 0;
  for(int i = 0; i < n; ++i){
    cin >> x;
    a = x;
    b = k-x;

    if(a>=b) sum += b * 2;
    else sum += a * 2;
  }
  cout << sum << "\n";
}