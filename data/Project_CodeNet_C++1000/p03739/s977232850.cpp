#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n;
  cin >> n;
  ll a_pos[n], a_neg[n];
  ll ans_pos=0, ans_neg=0;
  cin >> a_pos[0];
  a_neg[0] = a_pos[0];
  if(a_pos[0] <= 0){
    ans_pos += 1-a_pos[0];
    a_pos[0] = 1;
  }
  if(a_neg[0] >= 0){
    ans_neg += a_neg[0]+1;
    a_neg[0] = -1;
  }
  for(int i=1; i<n; i++){
    ll b;
    cin >> b;
    a_pos[i] = a_pos[i-1] + b;
    a_neg[i] = a_neg[i-1] + b;
    if(i%2==1){
      if(a_pos[i] >= 0){
        ans_pos += a_pos[i]+1;
        a_pos[i] = -1;
      }
      if(a_neg[i] <= 0){
        ans_neg += 1-a_neg[i];
        a_neg[i] = 1;
      }
    }else{
      if(a_pos[i] <= 0){
        ans_pos += 1-a_pos[i];
        a_pos[i] = 1;
      }
      if(a_neg[i] >= 0){
        ans_neg += a_neg[i]+1;
        a_neg[i] = -1;
      }
    }
  }
  ll ans = min(ans_pos, ans_neg);
  cout << ans << endl;
  return 0;
  
}
