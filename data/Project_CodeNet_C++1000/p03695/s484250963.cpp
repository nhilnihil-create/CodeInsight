#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >>n;
  int num[8]={0};
  int cnt = 0;
  rep(i,n){
    int a; cin >>a;
    if(a<=399) num[0]++;
    else if(a<=799) num[1]++;
    else if(a<=1199) num[2]++;
    else if(a<=1599) num[3]++;
    else if(a<=1999) num[4]++;
    else if(a<=2399) num[5]++;
    else if(a<=2799) num[6]++;
    else if(a<=3199) num[7]++;
    else if(a>=3200) cnt++;
  }
  int ans = 0;
  rep(i,8){
    if(num[i]>0) ans++;
  }
  if(ans==0) cout << 1 << " " << cnt << endl;
  else cout << ans << " " << ans+cnt << endl;
  return 0;
}
