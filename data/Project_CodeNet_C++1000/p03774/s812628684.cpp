#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> A(N),B(N),C(M),D(M);
  for(int i=0;i<N;i++){
    cin >> A.at(i) >> B.at(i);
  }
  for(int i=0;i<M;i++){
    cin >> C.at(i) >> D.at(i);
  }
  for(int i=0;i<N;i++){
    int minP=1000000000;
    int minQ=1000000000;
    //Pは距離、Qは対応する番号
    for(int j=0;j<M;j++){
      int P=abs(A.at(i)-C.at(j))+abs(B.at(i)-D.at(j));
      if(P<minP){
        minP=P;
        minQ=j+1;
      }
    }
    cout << minQ << endl;
  }
}