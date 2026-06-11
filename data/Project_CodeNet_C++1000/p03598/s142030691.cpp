#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;cin>>N>>K;
  vector<int> X(N),Y(N);
  int ans=0;
  for(int i=0;i<N;i++){
    cin>>X.at(i);
    Y.at(i)=K-X.at(i);
    ans+=min(X.at(i),Y.at(i));
  }
  cout<<ans*2<<endl;
}

