#include<bits/stdc++.h>
using namespace std;
int main(){
  string S,T="";
  cin >> S;
  //S.size();
  
  for(int i=0; i < S.size(); i++){
    if(S[i] == 'B'){
      if(T.size() == 0) continue;
      T.pop_back();
    }
    else T.push_back (S[i]);
  }
  cout << T << endl;
    
    return 0;
}
