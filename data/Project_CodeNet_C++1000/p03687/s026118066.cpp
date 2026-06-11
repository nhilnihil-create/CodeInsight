#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s;
  cin>>s;
  map<char,int> mp;
  rep(i,s.size()){
    mp[s[i]]++;
  }
  int ans=INT_MAX;
  for(auto x : mp){
    vector<int> index;
    index.push_back(-1);
    rep(i,s.size()){
      if(s[i]==x.first) index.push_back(i);
    }
    index.push_back(s.size());
    int div=0;
    for(int i=0; i<index.size()-1; i++){
      div=max(div,index[i+1]-index[i]-1);
    }
    ans=min(ans,div);
  }
  cout<<ans<<endl;
}
