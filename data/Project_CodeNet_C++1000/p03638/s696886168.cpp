#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,n,i,j,z;
  cin>>h>>w>>n;
  vector<int> c;
  for(i=1;i<=n;i++){
    cin>>z;
    for(j=0;j<z;j++) c.push_back(i);
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(j>0) cout<<' ';
      if(i%2==0) cout<<c.at(w*i+j);
      else if(i%2==1) cout<<c.at(w*i+w-1-j);
    }
    cout<<endl;
  }
}