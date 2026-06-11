#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N; cin>>N;
  vector<ll> vecA(N);
  rep(i,N)
  {
    cin>>vecA.at(i);
  }
  sort(vecA.begin(),vecA.end());
  /*rep(i,N)
  {
    if(i!=0) cout<<" ";
    cout<<vecA.at(i);
  }*/
  vector<ll> vecans(0);
  rep(i,N)
  {
    if(i==0) {vecans.push_back(vecA.at(0)); continue;}
    if(vecans.size()==0) {vecans.push_back(vecA.at(i)); continue;}
    if(vecA.at(i)==vecans.at(vecans.size()-1)) {vecans.pop_back(); continue;}
    vecans.push_back(vecA.at(i));
  }  
  cout<<vecans.size()<<endl;
  return 0;
}