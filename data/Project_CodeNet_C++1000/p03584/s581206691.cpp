#include<bits/stdc++.h>
using namespace std;
#define int long long 

int a[101010],b[101010];

signed main(void){
  int n,k; cin >> n >> k;
  for(int i = 0; i < n; i++){ 
    cin >> a[i] >> b[i];
  }
  
  //先ずはmskを変更しない
  int sum = 0;
  
  for(int i = 0; i < n; i++){ 
    bool ok = true;
    
    for(int j = 0; j <= 40; j++){ 
      if( !(k >> j & 1LL) && (a[i] >> j & 1)){
        ok = false;
      }
    }
    
    if(ok){ sum += b[i];}
  }
  
  int ans = sum;
  //次は0を立てる
  
  
  for(int i = 40; i >= 0; i--){ 
    
    sum = 0;
    
    if( k >> i & 1 ){ //このビットを０にして、それ未満を全て立てる
      
      int res = k;
      res = (res >> i)<<i;
      res--;
      
      for(int j = 0; j < n; j++){ 
        
        if( (a[j] | res) == res ){  sum += b[j];}
        
      }
      
    }

    ans = max(ans,sum);
    
  }
  
  cout << ans << endl;
  
  return 0;
}
