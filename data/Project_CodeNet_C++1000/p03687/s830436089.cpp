#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string s;
  cin>>s;
  map<char,pair<int,int>> A;
  for(char c='a';c<='z';c++)
    A[c]=make_pair(0,-1);
  for(int i=0;i<(int)s.size();i++){
    A[s[i]].first=max(A[s[i]].first,i-A[s[i]].second-1);
    A[s[i]].second=i;
  }
  int i=1000;
  for(pair<int,pair<int,int>> p:A)
    i=min(max(p.second.first,(int)s.size()-p.second.second-1),i);
  cout<<i<<endl;
}