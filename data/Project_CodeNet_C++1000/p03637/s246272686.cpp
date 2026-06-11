#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
  int n; cin >> n;
  int a[n];
  int two = 0;
  int four = 0;
  rep(i, n) {
    cin >> a[i];
    if(a[i] % 4 == 0) four++;
    else if(a[i] % 2 == 0) two++;
  }
  if(four * 2 + 1 >= n ||  four * 2 + two >= n) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0; 
}