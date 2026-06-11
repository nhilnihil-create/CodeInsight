#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >>n;
  vector<int> a(n);
  rep(i,n) cin >>a[i];
  int color[8] = {0};
  int cnt = 0;
  rep(i,n){
    if(a[i]<=399) color[0]++;
    else if(a[i]>=400 && a[i]<=799) color[1]++;
    else if(a[i]>=800 && a[i]<=1199) color[2]++;
    else if(a[i]>=1200 && a[i]<=1599) color[3]++;
    else if(a[i]>=1600 && a[i]<=1999) color[4]++;
    else if(a[i]>=2000 && a[i]<=2399) color[5]++;
    else if(a[i]>=2400 && a[i]<=2799) color[6]++;
    else if(a[i]>=2800 && a[i]<=3199) color[7]++;
    else if(a[i]>=3200) {
      cnt++;
    }
  }
  int ans = 0;
  rep(i,8){
    if(color[i]>0) ans++;
  }
  if(ans==0) cout << 1 << " " << ans+cnt << endl;
  else cout << ans << " " << ans+cnt << endl;
  return 0;
}
