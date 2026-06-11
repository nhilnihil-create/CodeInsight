#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  for(int i=0; i<S.size(); i++){
    if(i==5 || i==13){
      cout << " " ;
    }
    else{
      cout << S.at(i) ;
    }
  }
cout << endl;
}
