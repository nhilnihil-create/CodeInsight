#include<bits/stdc++.h>
using namespace std;

int isprime(int i){
  int S=sqrt(i);
  int Ans=1;
  for(int j=2; j<=S; j++){
    if(i%j==0){
      Ans=0;
      break;
    }
  }
  return Ans;
}

int main(){
  int N;
  cin >> N;
  vector<int> P(0);
  for(int i=2; i<1000; i++){
    if(isprime(i)==1){
      P.push_back(i);
    }
  }
  int L=P.size();
  vector<int64_t> D(L, 0);
  for(int i=1; i<=N; i++){
    for(int j=0; j<L; j++){
      int M=i;
      while(M%P.at(j)==0){
        D.at(j)++;
        M/=P.at(j);
      }
    }
  }
  int64_t Ans=1;
  for(int64_t i=0; i<L; i++){
    Ans*=D.at(i)+1;
    Ans%=1000000007;
  }
  cout << Ans << endl;
}