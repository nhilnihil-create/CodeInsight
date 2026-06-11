#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,count=0;
  cin >> N >> M;
  vector<int> A(M),B(M);
  for(int i=0;i<M;i++){
    cin >> A.at(i) >> B.at(i);
  }
  vector<int> num(N,1);
  vector<bool> C(N,false);
  C.at(0)=true;
  for(int i=0;i<M;i++){
    num.at(A.at(i)-1)--;
    num.at(B.at(i)-1)++;
    if(C.at(A.at(i)-1)){
      C.at(B.at(i)-1)=true;
    }
    if(num.at(A.at(i)-1)==0){
      C.at(A.at(i)-1)=false;
    }
  }
  for(int i=0;i<N;i++){
    if(C.at(i)){
      count++;
    }
  }
  cout << count << endl;
}