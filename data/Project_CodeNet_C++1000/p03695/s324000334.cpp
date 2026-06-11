#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,z,i,mi=0,ma;
  vector<int> x(9);
  cin>>n;
  for(i=0;i<n;i++){
    cin>>z;
    x.at(min(z/400,8))++;
  }
  for(i=0;i<8;i++) if(x.at(i)>0) mi++;
  ma=mi+x.at(8);
  if(mi==0) mi++;
  cout<<mi<<' '<<ma<<endl;
}