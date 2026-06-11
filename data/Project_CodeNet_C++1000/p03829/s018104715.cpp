#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t N, A, B;
  cin >> N >> A >> B;
  vector<int64_t> X(N);
  for(int64_t i=0; i<N; i++){
    cin >> X.at(i);
  }
  int64_t Ans=0;
  for(int64_t i=0; i<N-1; i++){
    if((X.at(i+1)-X.at(i))*A<B){
      Ans+=(X.at(i+1)-X.at(i))*A;
    }
    else{
      Ans+=B;
    }
  }
  cout << Ans << endl;
}