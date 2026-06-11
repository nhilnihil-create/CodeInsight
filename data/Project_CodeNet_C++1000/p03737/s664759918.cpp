#include <bits/stdc++.h>
using namespace std;

int main(){
  
  vector<char> AAA={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  vector<char> BBB={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  
  for(int i=0; i<3; i++){
    string x;
    cin >> x;
    for(int j=0; j<=25; j++){
      if(x.at(0)==AAA.at(j)){
        
        cout << BBB.at(j) ;
      }
    }
  }
  cout << endl;
}

