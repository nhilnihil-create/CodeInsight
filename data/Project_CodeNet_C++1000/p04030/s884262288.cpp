#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string S, data;;
  cin >> S;
  int i;
  
  for(i=0; i<(int)S.size(); i++){
    if(data.size()!=0 && S[i]=='B'){
      data.pop_back();
    }else if(S[i]=='1'){
      data+='1';
    }else if(S[i]=='0'){
      data+='0';
    }
  }
  cout << data << endl;
  return 0;
}