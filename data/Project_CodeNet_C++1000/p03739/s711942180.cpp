#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  ll n;
  cin >> n;
  ll a[n];
  rep(i, n){cin >> a[i];}

  ll sum1 = 0, sum2 = 0;
  ll ans1 = 0, ans2 = 0;

  rep(i, n){
      sum1 += a[i];
      if(i % 2){
        if(sum1 >= 0){
           ans1 += sum1 + 1;
           sum1 = -1; 
        }
      } else {
        if(sum1 <= 0){
          ans1 += (-sum1) + 1;
          sum1 = 1;
        }
      }
  }
  rep(i, n){
      sum2 += a[i];
      if(i % 2){
        if(sum2 <= 0){
          ans2 += (-sum2) + 1;
          sum2 = 1;
        }
      } else {
        if(sum2 >= 0){
          ans2 += sum2 + 1;
          sum2 = -1;  
        }
      }
  }
  cout << min(ans1, ans2) << endl;
}
