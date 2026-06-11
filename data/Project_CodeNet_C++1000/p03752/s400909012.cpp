#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  //vector<bool> see(n);
  ll count = 0;
  ll nowmax = 0;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    //see[i] = false;
    if(a[i] > nowmax){
      //see[i] = true;
      count++;
      nowmax = a[i];
    }
  }
  //cout << count << endl;
  if(k - count <= 0){
    cout << 0 << endl;
    return 0;
  }
  ll res = 0;
  res = pow(10,18);
  for(int i = 0;i < (1<<n); i++){//2のa乗回繰り返す(0 ~ 2^a- 1)
    ll nowcost = 0;
    ll keta = 0;
    ll purasu = 0;
    ll maxhigh = 0;
    for(int j = 0;j < n;j++){
      //if(!see[j]){
        if(i & (1<<j)){//小さい方からj桁目(0から)が1であったら
          if(a[j] < maxhigh + 1)purasu++,nowcost += maxhigh + 1 - a[j];
          //if(i == 31)cout << maxhigh << endl;
          //if(i == 11)cout << "j" << j << " " << nowcost << " " << maxhigh << endl;
              maxhigh = max(a[j],maxhigh + 1);
        }
      //}
      else{
        if(maxhigh < a[j])purasu++;
        maxhigh = max(maxhigh,a[j]);
      }
      if(purasu >= k){
        res = min(res,nowcost);
        //cout << nowcost << endl;
        //if(nowcost == 8)cout << "i" << i << endl;
      }
    }
  }
  cout << res << endl;
}