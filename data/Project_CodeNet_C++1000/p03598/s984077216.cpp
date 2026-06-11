#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n, k, x, t = 0;
  cin >> n >> k;
  rep(i,n){
    cin >> x;
    if(2 * x < k)
      t += 2 * x;
    else
      t += 2 * (k - x);
  }
  cout << t << endl;
}