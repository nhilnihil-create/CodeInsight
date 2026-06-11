#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  long n, m, l, minus;
  cin >> n;
  m = 0;
  vector<long> vec(n);
  l = n / 2;
  if(n == (n / 2) * 2) minus = 1;
  else minus = -1;
  rep(i, n){
    l += minus * i;
    cin >> vec[l];
    minus *= -1;
  }
  rep(i, n){
    if(i == 0) cout << vec[i];
    else cout << " " << vec[i];
  }
  cout << endl;
}