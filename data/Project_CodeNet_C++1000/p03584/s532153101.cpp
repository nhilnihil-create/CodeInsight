#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

signed main(void){ 
  
  int N,K; cin >> N >> K;
  vector<int> A(N),B(N);
  for(int i = 0; i < N; i++){
    cin >> A[i] >> B[i];
  } 
  int ans = 0;
  
  for(int i = 40; i >= 0; i--){ 
    // Kの上の桁から見て行って、1がないかを探す
    if( !(K >> i & 1) && i < 40) { continue;}
    
    
    int res = K;
    //この桁を0にして、それより下の桁を全て1にする
    
    if( i < 40 ){ res = (res>>i)<<i; res--;}
    
   
    int inst = 0;
   vector<int> row;
    
    for(int j = 0; j < N; j++){ 
      
      if( (A[j] | res) == res ){ inst+= B[j]; row.push_back(A[j]);}
      
    }
   
    ans = max(ans,inst);
  }
  
  cout << ans << endl;
  
  return 0;
}
    
    