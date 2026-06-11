#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  vector<int>v(N);
  long long K=0;
  for(int X=0;X<N;X++){
    cin>>v[X];
    K+=v[X];
  }
  int M;cin>>M;
  vector<int>P(M);
  vector<int>Q(M);
  vector<int>R(M);
  for(int X=0;X<M;X++){
    cin>>P[X]>>Q[X];
    cout<<K+(Q[X]-v[P[X]-1])<<endl;
  }
}