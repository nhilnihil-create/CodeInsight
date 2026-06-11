#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli>> mat;

lli n,m;
vll a;
vll b;
vll imos;
lli ans,y;

lli calc(lli x){
  lli ret = 0;
  for(lli i = 1;i < n;i++) ret += min((a[i]+m-a[i-1])%m,(a[i]+m-x)%m+1);
  return ret;
}

int main(){
  cin >> n >> m;
  a = vll(n);
  for(lli i = 0;i < n;i++) cin >> a[i];
  imos = vll(2*m+1);
  for(lli i = 1;i < n;i++){
    if(a[i] < a[i-1]){
      imos[a[i]+m]--;
      imos[a[i-1]]++;
    }else{
      imos[a[i]]--;
      imos[a[i-1]]++;
    }
  }
  for(lli i = 1;i <= 2*m;i++) imos[i] += imos[i-1];
  b = vll(m+1);
  for(lli i = 1;i < n;i++){
    b[a[i]] += (a[i]+m-a[i-1])%m;
  }
  // for(lli i = 1;i <= m;i++) cout << calc(i) << " " << imos[i]+imos[i+m] << endl;
  // cout << "-" << endl;
  ans = y = calc(1);
  // cout << y << endl;
  for(lli i = 1;i < m;i++){
    y = y-imos[i-1]-imos[i+m-1]+b[i];
    // cout << y << endl;
    ans = min(ans,y);
  }
  cout << ans << endl;
  return 0;


}
