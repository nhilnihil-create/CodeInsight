#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string s, t;
  cin >> N >> s >> t;
  int k;
  int Ans=-1;
  for(int i=0; i<=N; i++){
    k=1;
    for(int j=0; j<N-i; j++){
      if(s.at(j+i)!=t.at(j)){
        k=0;
        break;
      }
    }
    if(k==1){
      Ans=i;
      break;
    }
  }
  cout << Ans+N << endl;
}