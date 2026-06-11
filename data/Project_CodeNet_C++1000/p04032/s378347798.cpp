#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string S;cin >> S;
  int N = S.size();
  if(N==2){
    if(S[0]==S[1]){
      cout << "1 2" << endl;
    }else{
      cout << "-1 -1" << endl;
    }
    return 0;
  }
  for(int i=0;i<N-2;i++){
    char x = S[i],y = S[i+1],z = S[i+2];
    if(x==y||y==z||z==x){
      cout << i+1 << " " << i+3 << endl;
      return 0;
    }
  }
  cout << "-1 -1" << endl;
}