#include<bits/stdc++.h>
using namespace std;

int main() {
  string A;
  cin >> A;
  bool N=false,E=false,W=false,S=false;
  for(int i=0;i<A.size();i++){
    if(A.at(i)=='N'){
      N=true;
    }
    else if(A.at(i)=='E'){
      E=true;
    }
    else if(A.at(i)=='W'){
      W=true;
    }
    else{
      S=true;
    }
  }
  if((N && E && W && S) || (!N && E && W && !S) || (N && !E && !W && S)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
    
    
  
