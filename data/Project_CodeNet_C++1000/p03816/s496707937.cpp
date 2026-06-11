#include<bits/stdc++.h>
using namespace std;
int main(){
  int m,j,k=0;
  cin>>m;
  vector<int> x(m);
  for(j=0;j<m;j++) cin>>x.at(j);
  sort(x.begin(),x.end());
  for(j=1;j<m;j++) if(x.at(j)==x.at(j-1)) k++;
  if(k%2==1) k++;
  cout<<m-k<<endl;
}