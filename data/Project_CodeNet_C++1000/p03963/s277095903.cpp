#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin>>N>>K;
  int pattern=1;
  for(int i=1;i<=N;i++){
    if(i==1){
      pattern*=K;
    }
    else{
      pattern*=(K-1);
    }
  }
    cout<<pattern<<endl;
}
