#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int>L(2*N);
  for(int i=0;i<2*N;i++)
    cin>>L.at(i);
  sort(L.begin(),L.end());
  int ans=0;
  for(int i=0;i<N;i++)
    ans+=L.at(2*i);
  cout<<ans<<endl;
     return 0;
}