#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,i,c=1;
  cin>>n;
  vector<int64_t> a(n);
  vector<pair<int64_t,int64_t>> b;
  for(i=0;i<n;i++) cin>>a.at(i);
  sort(a.begin(),a.end());
  for(i=1;i<n;i++){
    if(a.at(i)==a.at(i-1)) c++;
    else{
      if(c>1) b.push_back(make_pair(a.at(i-1),c));
      c=1;
    }
  }
  if(c>1) b.push_back(make_pair(a.at(i-1),c));
  if(b.size()<1) cout<<0<<endl;
  else if(b.size()==1&&b.at(0).second<4) cout<<0<<endl;
  else{
    reverse(b.begin(),b.end());
    if(b.at(0).second>=4) cout<<b.at(0).first*b.at(0).first<<endl;
    else cout<<b.at(0).first*b.at(1).first<<endl;
  }
}