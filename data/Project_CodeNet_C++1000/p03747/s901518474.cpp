#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int64_t N,S,T;
  cin >> N >> S >> T;
  vector<int64_t> X(N),W(N);
  for(int i=0;i<N;i++){
    cin >> X.at(i) >> W.at(i);
  }
  int64_t y=0,x;
  if(W.at(0)==1){
    for(int i=1;i<N;i++){
      if(W.at(i)==2){
        if((2*T)%S<X.at(i)-X.at(0)){
          y+=(2*T)/S;
        }else{
          y+=(2*T)/S+1;
        }
      }
    }
    y%=N;
    x=(X.at(0)+T)%S;
  }else{
    for(int i=1;i<N;i++){
      if(W.at(i)==1){
        if((2*T)%S<X.at(0)-X.at(i)+S){
          y+=(2*T)/S;
        }else{
          y+=(2*T)/S+1;
        }
      }
    }
    y%=N;
    y=N-y;
    if(y>N) y-=N;
    x = (X.at(0)-T)%S;
      if(x<0){
          x+=S;
        }
  }
  
  int64_t z;
  vector<int64_t> A(N);
  for(int i=0;i<N;i++){
    if(W.at(i)==1){
      A.at(i)=(X.at(i)+T)%S;
    }else{
      z = (X.at(i)-T)%S;
      if(z<0){
          z+=S;
        }
      A.at(i)=z;
    }
  }
  sort(A.begin(), A.end());
  for(int i=0;i<N;i++){
    if(A.at(i)==x){
      if(i==N-1){
        y=(N+i-y)%N;
        break;
      }
      if(A.at(i+1)!=x){
        y=(N+i-y)%N;
        break;
      }else{
        if(W.at(0)==1){
          y=(N+i+1-y)%N;
          break;
        }else{
          y=(N+i-y)%N;
          break;
        }
      }
    }
  }
  for(int i=y;i<N+y;i++){
    cout << A.at(i%N) << endl;
  }
}
    