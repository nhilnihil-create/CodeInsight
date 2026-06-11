#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  map<int,int> num;

  int M = -1;
  rep(i,n){
    int tmp; cin >> tmp;
    M = max(tmp,M);
    num[tmp]++;
  }

  int ans = num[0]+num[1]+num[2];
  int sum = ans;
  for(int i = 1;i<=M;i++){
    
    sum = sum-num[i-1]+num[i+2];
    ans = max(ans,sum);
  }
  
  cout << ans << endl;
  
  return 0;
}
