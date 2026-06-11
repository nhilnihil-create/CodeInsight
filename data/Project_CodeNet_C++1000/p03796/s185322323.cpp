#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  long long ans=1;
  rep(i,N){
    ans *= (i+1);
    ans %= 1000000007;
  }
  
  cout << ans << endl;

}