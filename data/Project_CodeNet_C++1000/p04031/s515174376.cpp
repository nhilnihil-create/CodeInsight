#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
  
int main(){
  int N,total =0; cin >> N;
  int a[N]; 
  rep(i,N) {
    cin >> a[i]; total += a[i];
  }
  
  int ave =total / N;
  int ans, ans1 =0, ans2 =0;
  rep(i,N) ans1 += (a[i] - ave) * (a[i] - ave);  
  rep(i,N) ans2 += (a[i] - ave -1) * (a[i] - ave -1);  
  
  ans = min(ans1,ans2);
  cout << ans << endl;
}