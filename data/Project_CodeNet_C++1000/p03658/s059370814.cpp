#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  vector<int> l(N);
  for(int &i:l)
    cin>>i;
  sort(l.begin(),l.end());
  int j=0;
  for(int i=1;i<=K;i++)
    j+=l[N-i];
  cout<<j<<endl;
}