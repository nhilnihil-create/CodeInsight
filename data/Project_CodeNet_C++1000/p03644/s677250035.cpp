#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  
  int count;
  int max = 0;
  int ans = 1;
  rep(i, n){
    count = 0;
    int num = i;
    while(1){
      if (num % 2 == 1) break;
      if (num == 0) break;
      num /= 2;
      ++count;
    }
    if (max < count){
      max = count;
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}