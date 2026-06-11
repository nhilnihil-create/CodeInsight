#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  vector<int>L(N);
  for(int i=0;i<N;i++){
    cin>>L.at(i);
  }
  sort(L.begin(),L.end());
  reverse(L.begin(),L.end());
  int sum=0;
  for(int i=0;i<K;i++){
    sum=sum+L.at(i);
  }
  cout<<sum<<endl;
}