#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  int n,l;
  cin>>n>>l;
  vector<string> s(n);
  for(auto&& e: s) 
  {
    cin>>e;
  }
  sort(s.begin(), s.end());
  for(auto&& e: s) 
  {
    cout<<e;
  }
  cout<<endl;
}