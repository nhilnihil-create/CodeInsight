#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
  int a;
  cin >> a;
  long long ans = 1;
  for(int i = 1; i <= a; i++){
    ans *= i;
    ans %= MOD;
  }
  cout << ans << endl;
}