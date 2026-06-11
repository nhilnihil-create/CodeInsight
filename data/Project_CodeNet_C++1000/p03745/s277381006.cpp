#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  int N; cin>>N;
  vector<int> A(N);
  rep(i,N)
  {
    cin>>A.at(i);
  }
  vector<bool> vec(0);
  rep(i,N)
  {
    if(i==0) {continue;}
    if(A.at(i)>A.at(i-1)) {vec.push_back(true);}
    if(A.at(i)<A.at(i-1)) {vec.push_back(false);}
  }
  int ans=0;
  rep(i,vec.size())
  {
    if(i==0) {continue;}
    if(vec.at(i)!=vec.at(i-1)) {ans++; i++;}
  }
  cout<<ans+1<<endl;
  return 0;
}
