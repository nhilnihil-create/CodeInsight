#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string s,t;
  cin >> N >> s >> t;
  if(s==t){
    cout << N << endl;
  }else{
    for(int i=1;i<N;i++){
      if(s.substr(i,N-i)==t.substr(0,N-i)){
        cout << N-i+2*i << endl;
        return 0;
      }
    }
    cout << 2*N << endl;
  }
  return 0;
}
