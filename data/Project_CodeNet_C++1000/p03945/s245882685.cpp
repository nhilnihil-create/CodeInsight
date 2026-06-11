#include<bits/stdc++.h>
using namespace std;
int main()
{
  string a;std::cin>>a;
  int ans=1;
  for(int i=1;i<a.size();i++){
    ans+=a[i]!=a[i-1];
  }
  ans--;
  std::cout<<ans;
  return 0;
}
