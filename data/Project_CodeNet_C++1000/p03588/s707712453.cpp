#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >>n;
  int curMax = 0;
  int ans = 0;
  rep(i,n){
    int a,b;
    cin >>a >>b;
    if(a>curMax) {
      curMax = a;
      ans = a+b;
    }
  }
  cout << ans << endl;
  return 0;
}