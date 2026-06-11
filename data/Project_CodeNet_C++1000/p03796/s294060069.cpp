#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
  long int n, i = 1;
  cin >> n;
  for(long int j = 1; j <= n; j++){
    i *= j;
    i %= MOD;
  }
  cout << i << endl;
  return 0;
}
