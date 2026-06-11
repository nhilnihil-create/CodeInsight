#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int k,s;
  cin >> k >> s;
  int ans = 0;
  for (int i = 0;i <= k;i++){
    for (int j = 0; j <= k;j++){
      if (s-i-j >= 0 &&  s-i-j <= k) ans++;
    }
  }
  cout << ans << endl;
  

  
  return 0;
  
}
