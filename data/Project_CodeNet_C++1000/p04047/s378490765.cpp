#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> L(2*N);
  for(int &i:L)
    cin>>i;
  sort(L.begin(),L.end());
  int j=0;
  for(int i=0;i<N;i++)
    j+=L[i*2];
  cout<<j<<endl;
}