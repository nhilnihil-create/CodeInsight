#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> sc(n); rep(i,n) cin >> sc[i];
  int sum = 0;
  sort(sc.begin(),sc.end());
  rep(i,n) sum+=sc[i];

  if(sum%10 != 0){
    cout << sum << endl;
    return 0;
  }
  
  rep(i,n){
    if(sum%10 == 0){
      sum -= sc[i];
    }
    if(sum%10 != 0){
      cout << sum << endl;
      return 0;
    }
    sum += sc[i];
  }

  if(sum%10 == 0){
    sum = 0;
    cout << sum << endl;
  }
  
  return 0;
}
