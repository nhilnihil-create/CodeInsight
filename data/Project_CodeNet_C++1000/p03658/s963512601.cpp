#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; int K; cin>>N>>K;
  vector<int> S(N);
  for(int i=0; i<N; i++){
    cin>>S.at(i);
  }
  sort(S.begin(),S.end());
  reverse(S.begin(),S.end());
  int L=0;
  for(int i=0; i<K; i++){
    L+=S.at(i);
  }
  cout<<L<<endl;
}