#include <bits/stdc++.h>
using namespace std;
int main(){
  long long ago=0;
  int N,K; cin>>K>>N;
  for(int i=0;i<=K;i++){
    for(int j=0;j<=K;j++){
      if(N-i-j>=0&&N-i-j<=K)ago++;
    }
  }
  cout<<ago<<endl;
}