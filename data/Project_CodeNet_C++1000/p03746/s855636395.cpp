#include <bits/stdc++.h>
using namespace std;

int main(){
  int ans=0;
  int N,M;
  cin>>N>>M;
  std::vector<int> v(N,0),w[N];
  int a,b;
  for(int i=0;i<M;i++){
    cin>>a>>b;
    a--;b--;
    w[a].push_back(b);
    w[b].push_back(a);
  }
  stringstream ss;
  int j;
  for(int i=0;i<N;i++){
    if(w[i].size()){
      ss<<i+1;
      j=i;
      v[i]++;
      break;
    }
  }
  ans++;
  int k=j;
  bool f=true;
  while(f){
    for(int i=0;i<w[j].size();i++){
      if(v[w[j][i]]==0){
        ss<<" "<<w[j][i]+1;
        ans++;
        v[w[j][i]]++;
        j=w[j][i];
        break;
      }
      if(i==w[j].size()-1)f=false;
    }
  }
  j=k;
  f=true;
  std::vector<string> sss;
  while(f){
    for(int i=0;i<w[j].size();i++){
      if(v[w[j][i]]==0){
        sss.push_back(" ");
        sss.push_back((to_string)(w[j][i]+1));
        ans++;
        v[w[j][i]]++;
        j=w[j][i];
        break;
      }
      if(i==w[j].size()-1)f=false;
    }
  }
  reverse(sss.begin(),sss.end());
  cout<<ans<<endl;
  for(int pp=0;pp<sss.size();pp++)cout<<sss[pp];
  cout<<ss.str()<<endl;
}
