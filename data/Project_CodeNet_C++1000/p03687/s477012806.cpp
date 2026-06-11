#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  vector<pair<int,int> > vp(26,pair<int,int>(-1,-1));
  int x;
  int N=s.size();
  for(int i=0;i<N;i++){
    x=s.at(i)-'a';
    vp.at(x).second=max(vp.at(x).second,i-vp.at(x).first-1);
    vp.at(x).first=i;
  }
  int ans=1e8;
  for(auto p:vp){
    if(p.first!=-1){
      ans=min(ans,max(p.second,N-p.first-1));
    }
  }
  cout << ans << endl;
  return 0;
}
