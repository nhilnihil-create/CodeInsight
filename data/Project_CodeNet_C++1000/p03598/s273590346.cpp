#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, k, x, ans = 0;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> x;
    if(x >= k - x){
  	  ans += (k - x) * 2;
    }else if(x < k - x){
  	  ans += x * 2;
    }
  }
  cout << ans;
}