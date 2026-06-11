#include<bits/stdc++.h>
using namespace std;

int64_t Con(int a, int b){
  int64_t Ans=1;
  for(int i=0; i<b; i++){
    Ans*=a-i;
    Ans/=i+1;
  }
  return Ans;
}

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  vector<int64_t> V(N);
  for(int i=0; i<N; i++){
    cin >> V.at(i);
    V.at(i)*=-1;
  }
  sort(V.begin(), V.end());
  for(int i=0; i<N; i++){
    V.at(i)*=-1;
  }
  double Ave=0;
  for(int i=0; i<A; i++){
    Ave+=(double)V.at(i)/(double)A;
  }
  cout << setprecision(20) << Ave << endl;
  int first=0;
  int count=0;
  int t=0;
  for(int i=0; i<N; i++){
    if(V.at(i)==V.at(A-1)){
      if(t==0){
        first=i;
        t=1;
      }
      count++;
    }
  }
  int64_t Ans=0;
  for(int i=A-first; i<=B-first; i++){
    Ans+=Con(count, i);
  }
  if(V.at(0)==V.at(A-1)){
    cout << Ans << endl;
  }
  else{
    cout << Con(count, A-first) << endl;
  }
}