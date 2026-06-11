#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin>>N>>M;
  vector<int> num(N,1);
  vector<bool> ans(N,false);
  ans.at(0)=true;
  for(int i=0;i<M;i++){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    num.at(x)--;
    num.at(y)++;
    if(ans.at(x)) ans.at(y)=true;
    if(num.at(x)==0) ans.at(x)=false;
    }
  int count=0;
  for(int i=0;i<N;i++) if(ans.at(i)) count++;
  cout<<count<<endl;
  }