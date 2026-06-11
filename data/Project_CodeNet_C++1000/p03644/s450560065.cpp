#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;

  int num = -1;
  int ans;
  for(int i = 1;i<=n;i++){
    int tmp = 0;
    int k = i;
    while(k%2==0){
      k /= 2;
      tmp++;
      if(k==1||k==0) break;
    }
    num = max(tmp,num);
    if(num==tmp) ans = i;
  }

  cout << ans << endl;
  
  return 0;
}
