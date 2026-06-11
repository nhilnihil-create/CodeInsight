#include<bits/stdc++.h>

using namespace std;

int main(){
  int N; cin >> N;
  vector<int> a(N);
 
  int ma = 1e8; int Ma = 0;
  for(int i = 0; i < N; i++){ 
    cin >> a[i]; ma = min(ma,a[i]); Ma = max(Ma,a[i]);

  }
  
  if( Ma-ma > 1){ cout << "No" << endl; return 0;}
  
    if( Ma == ma){
    
    //全員aloneか、全員aloneでない
    
    if( a[0] == N-1 || 2*a[0] <= N){ cout << "Yes" << endl;}
    else{ cout << "No" << endl;}
    
    
  } //aloneがいないとき
  
  else{
    
    int x = 0;
    
    for(int i = 0 ; i < N; i++){
      if( a[i] == ma){ x++;}
    }
   
    if( 2*Ma <= N+x &&  0 < x && x < Ma){ cout << "Yes" << endl;}
    
    else{ cout << "No" << endl;}
    
   
  }
  
  return 0;
  
}
  