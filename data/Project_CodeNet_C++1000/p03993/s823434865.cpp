#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N+1, 0);
  for(int i=1; i<=N; i++){
    cin >> A.at(i);
  }
  int Ans=0;
  for(int i=1; i<=N; i++){
    if(A.at(A.at(i))==i){
      Ans++;
    }
  }
  cout << Ans/2 << endl;
}