#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  int n;
  cin>>n;
  vector<int> a(n);
  for(auto&& e: a) 
  {
    cin>>e;
    e--;
  }
  int ans=0;
  for (int i = 0; i < n; ++i)
  {
    if(a[a[i]]==i) ans++;
  }
  cout<<ans/2<<endl;
}