#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,C,K;
  cin >> N >> C >> K;
  
  vector<long long> T(N);
  for(int i=0;i<N;i++){
    cin >> T.at(i);
  }
  sort(T.begin(),T.end());
  
  long long bus = 0;
  long long tmp = 0;
  long long time = T.at(0);
  for(int i=0;i<N;i++){
    if(tmp==0){
      time = T.at(i);
    }
    if( T.at(i) - time > K ){
      bus ++;
      tmp = 1;
      time = T.at(i);
    }else{
      tmp++;
      if( C == tmp ){
        bus ++;
        tmp = 0;
      }
    }
  }

  if( tmp > 0){
    bus ++;
  }

  cout << bus << "\n";
}