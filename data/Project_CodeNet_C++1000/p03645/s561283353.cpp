#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>&has,vector<bool>&sumi,int now,int N,int time){
  if(now==N)
    return true;
  if(sumi.at(now))
    return false;
  if(time>=2)
    return false;
  sumi.at(now)=true;
  bool ans=false;
  for(int i=0;i<has.at(now).size();i++){
    ans=ans||check(has,sumi,has.at(now).at(i),N,time+1);
  }
  return ans;
}

int main(){
  int N,M,b,bb;
  cin >> N >> M;
  vector<vector<int>>br(N);
  for(int i=0;i<M;i++){
    cin >> b >> bb;
    br.at(b-1).push_back(bb-1);
    br.at(bb-1).push_back(b-1);
  }
  vector<bool>sumi(N,false);
  cout << (check(br,sumi,0,N-1,0)?"POSSIBLE":"IMPOSSIBLE") << endl;
  return 0;
}
  