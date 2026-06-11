#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set> 
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

bool dp[2][10001];
 
int main(){
  int n;
  cin >> n;
  dp[0][0] = true;
  dp[1][0] = true;
  int one = 0;
  int two = 1;
  for (int i = 0; i < n;i++){
    int tmp;
    cin >> tmp;
    for (int j = 0; j < 10001;j++){
      if (j+tmp <= 10000 && dp[one][j]) {
        dp[two][j+tmp] = true;
        dp[two][j] = true;
      }
    }
    swap(one,two);
  }
  int ans = 0;
  for (int i = 0; i < 10001;i++){
    if (i%10 != 0 && dp[one][i]) ans = i;
  }
  cout << ans << endl;
  
  
  return 0; 
}

