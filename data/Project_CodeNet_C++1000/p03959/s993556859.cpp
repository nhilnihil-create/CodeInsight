#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int64_t Z=1;
  vector<int> T(N);
  vector<int> A(N);
  vector<int> H(N,-1);
  for(int i=0;i<N;i++){
    cin>>T.at(i);
  }
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  H.at(0)=T.at(0);
  H.at(N-1)=A.at(N-1);
  for(int i=1;i<N;i++){
    if(T.at(i)!=T.at(i-1)){
      if(H.at(i)==-1||H.at(i)==T.at(i)){
        H.at(i)=T.at(i);
      }
      else{
        Z=0;
      }
    }
  }
  for(int i=N-2;i>=0;i--){
    if(A.at(i)!=A.at(i+1)){
      if(H.at(i)==-1||H.at(i)==A.at(i)){
        H.at(i)=A.at(i);
      }
      else{
        Z=0;
      }
    }
  }
  for(int i=0;i<N;i++){
    if(H.at(i)==-1){
      Z*=min(A.at(i),T.at(i));
      Z%=1000000007;
    }
    else if(H.at(i)>min(A.at(i),T.at(i))){
      Z=0;
    }
  }
  if(N==1&&T.at(0)!=A.at(0)){
    Z=0;
  }
  cout<<Z<<endl;
}