#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ; 
  vector<int> a(N) ; 
  int over = 0 ;
  int cnt = 0 ; 
  
  for(int i = 0 ; i < N ; i++){
    cin >> a.at(i) ; 
    a.at(i) = a.at(i)/400 ;
    if(a.at(i) >= 8){
      over++ ; 
    }
    else{
      int T = 0 ; 
      for(int j = 0 ; j <= i ; j++){
        if(a.at(i) == a.at(j)){
          T++ ; 
        }
      }
      if(T == 1){
      cnt++ ; 
      }
    }

    //cout << a.at(i) << " " << cnt << endl ; 
  }
  
  if(cnt == 0 ){
    cout << 1  ; 
  }
  else {
    cout << cnt  ;   
  }
  

  if(  over > 0 ){
    cnt = cnt + over ; 
    }
    
  cout << " " << cnt << endl ; 
  return 0 ; 
  
}
