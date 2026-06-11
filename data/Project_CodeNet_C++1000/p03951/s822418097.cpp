#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  
  int N;
  string S,T;
  bool torf=false;
  int i=0,j=0;
  
  cin >> N >> S >> T;
  
  while(i<N){
  if(T.at(0)==S.at(i)){
    while(j+i<N && T.at(j)==S.at(j+i)){
      if(T.at(N-i-1)==S.at(N-1))
        torf=true;
      
      j++;
    }
    if(torf==true)
      break;
    j=0;
  }
    i++;
  }
  
  
  if(torf==true){
    cout << i+N << endl;
  //cout << i << endl;
  }
  else
    cout << 2*N << endl;
}