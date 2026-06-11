#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int x,y,num;
  cin >> x >> y;
  vector<int> A{1,3,5,7,8,10,12};
  vector<int> B{4,6,9,11};
  
  if(x == y && x == 2){
    cout << "Yes" << endl;
    return 0;
  }
  bool xa = false, ya = false;
  for(int i = 0; i < 6; i++){
    if(x == A.at(i)){
      xa = true;
    }
    if(y == A.at(i)){
      ya = true;
    }
  }
  if(xa && ya){
    cout << "Yes" << endl;
    return 0;
  }
    
    xa = false, ya = false;
  for(int i = 0; i < 4; i++){
    if(x == B.at(i)){
      xa = true;
    }
    if(y == B.at(i)){
      ya = true;
    }
  }
  if(xa && ya){
    cout << "Yes" << endl;
    return 0;
  }
  
  cout << "No" << endl;
}