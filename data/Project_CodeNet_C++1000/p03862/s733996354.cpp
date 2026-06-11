#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,X;
  cin >> N >> X;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  long long count=0;
  for(int i=0;i<N-1;i++){
    int B=A.at(i)+A.at(i+1);
    if(B<=X){
      continue;
    }
    int C=B-X;
    count+=C;
    if(A.at(i+1)>=C){
      A.at(i+1)-=C;
      C=0;
    }
    else{
      A.at(i+1)=0;
    } 
  }
  cout << count << endl;
} 