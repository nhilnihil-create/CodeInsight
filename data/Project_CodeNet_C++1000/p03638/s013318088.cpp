#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,n;
  cin>>h>>w>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  vector<vector<int>> c(h,vector<int>(w));
  int x=0;
  for(int i=0;i<h;i++){
    bool p=(i%2==0);
    for(int j=(p?0:w-1);j<w&&j>=0;j+=(p?1:-1)){
      c.at(i).at(j)=x+1;
      a.at(x)--;
      if(a.at(x)==0)
        x++;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)
      cout<<c.at(i).at(j)<<' ';
    cout<<endl;
  }
}
