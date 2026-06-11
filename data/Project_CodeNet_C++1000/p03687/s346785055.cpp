#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
  string s;
  cin>>s;
  vector<vector<int>> index(26);
  for(int i=0;i<26;i++){
    index.at(i).push_back(-1);
  }
  int n=s.size();
  for(int i=0;i<n;i++){
    int x=s.at(i)-'a';
    index.at(x).push_back(i);
  }
  for(int i=0;i<26;i++){
    index.at(i).push_back(n);
  }

  int ans=1000000;
  for(int i=0;i<26;i++){
    int sub=0;
    for(int j=1;j<index.at(i).size();j++){
      sub=max(sub,index.at(i).at(j)-index.at(i).at(j-1)-1);
    }
    ans=min(sub,ans);
  }
  cout<<ans<<endl;
}
