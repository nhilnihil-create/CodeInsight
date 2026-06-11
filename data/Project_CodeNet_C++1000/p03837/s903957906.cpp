#include<bits/stdc++.h>
using namespace std;
int main(){
  int l,m,x,y,z,i,j,k,q=0;
  cin>>l>>m;
  vector<vector<int>> d(l,vector<int>(l,1e9)),r(m,vector<int>(3));
  for(j=0;j<l;j++) d.at(j).at(j)=0;
  for(j=0;j<m;j++){
    cin>>x>>y>>z;
    x--;y--;
    d.at(x).at(y)=z;
    d.at(y).at(x)=z;
    r.at(j).at(0)=x;
    r.at(j).at(1)=y;
    r.at(j).at(2)=z;
  }
  for(k=0;k<l;k++){
    for(i=0;i<l;i++){
      for(j=0;j<l;j++){
        d.at(i).at(j)=min(d.at(i).at(j),d.at(i).at(k)+d.at(k).at(j));
      }
    }
  }
  for(j=0;j<m;j++) if(d.at(r.at(j).at(0)).at(r.at(j).at(1))<r.at(j).at(2)) q++;
  cout<<q<<endl;
}