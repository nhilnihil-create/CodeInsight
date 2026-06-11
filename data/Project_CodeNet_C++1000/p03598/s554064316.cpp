#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  int x;
  int ans = 0;
  
  while(n > 0){
    cin >> x;
    if(x <= k-x){
      ans += 2*x;
    }else{
      ans += 2*(k-x);
    }
    
    n--;
  }
  
  cout << ans << endl;
}