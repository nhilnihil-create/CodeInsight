#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int a,b;
  cin >> a >> b;
  vector<int> c={ 0,1,3,1,2,1,2,1,1,2,1,2,1 };
  
  if( c.at(a) == c.at(b) ){
    
    cout << "Yes" << endl;
    
  }
  
  else{
    
    cout << "No" << endl;
    
  }
  
}
  
