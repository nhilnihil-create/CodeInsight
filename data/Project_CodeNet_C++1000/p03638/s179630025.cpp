#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  int h,w,n;cin>>h>>w>>n;
  vector<int> a(h*w,0);
  vector<vector<int>> m(h,vector<int>(w,0));

  int c=0;
  REP(i,n){
    int t;cin>>t;
    REP(j,t){
      a.at(c)=i+1;
      c++;
    }
  }

  c=0;
  REP(i,h){
    if(!(i%2)) for(int j=0;j<w;j++){
      m.at(i).at(j)=a.at(c);
      c++;
    }else for(int j=w-1;j>=0;j--){
      m.at(i).at(j)=a.at(c);
      c++;      
    }
  }

  REP(i,h){
    REP(j,w) cout<<m.at(i).at(j)<<" ";
    cout<<endl;
  }
  
}
