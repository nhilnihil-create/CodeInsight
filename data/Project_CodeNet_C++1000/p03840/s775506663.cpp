#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

signed main(void){
  
  int i,o,t,j,l,s,z;
  
  cin >> i >> o >> t >> j >> l >> s >> z;
  
  int sum = 2*o; // Kではなく2*Kを求めていることに注意
  
  int ans1 = sum,ans2 = sum;
  
  { //I+J+Lを作る場合
    
    bool flag = false;
    
    if( i && j && l ){
      i--; j--; l--; ans1 += 6;
      flag = true;
    }

    ans1 += 4*(j/2); ans1 += 4*(l/2);
    ans1 += 4*(i/2);
    
    if(flag){ i++; j++; l++;}
    
    
  }
  {
    //作らない場合
    ans2 += 4*(j/2); ans2 += 4*(l/2); ans2 += 4*(i/2);
  }
  
  cout << max(ans1,ans2)/2 << endl; return 0;
}