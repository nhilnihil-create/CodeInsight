#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string s,t;
  cin >> s >> t;
  int ans = 2*N;
  int i = 0;
  while(i<N){
  bool b = true;
    for(int j = 0; i+j<N; j++){
      if(s.at(i+j) !=t.at(j)){
        b = false;
      }
    }
      if(b == true){
        cout << ans -(N-i) << endl;
        return 0;
      }
      else{
        i ++;
      }
      }
    cout << 2*N << endl;
  }