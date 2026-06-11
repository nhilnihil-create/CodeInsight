#include<bits/stdc++.h>

using namespace std;

int main(){
  string S; cin>> S;
  if( (int)S.size() < 4){ cout << "No" <<endl; return 0;}
 
  if( S[0] == 'Y' && S[1] == 'A' && S[2] == 'K' && S[3] == 'I'){
    cout << "Yes" << endl;}
  else{ cout << "No" <<endl;}
  
  return 0;}