#include<bits/stdc++.h>
using namespace std ;

int main(){
  string A ,B ; 
  cin >> A >> B ; 
  
  if(A.size() > B.size()){
    cout << "GREATER" << endl ; 
  }
  else if (A.size() < B.size()){
    cout << "LESS" << endl;
  }
  else{
    for(int i = 0 ; i < A.size() ; i++){
      if(A.at(i) > B.at(i)){
        cout << "GREATER" << endl ; 
        return 0 ; 
      }
      else if(A.at(i) < B.at(i) ){
        cout << "LESS" << endl ; 
        return 0 ; 
      }
    }
    
    cout << "EQUAL" << endl ; 
  }
  
  
}
