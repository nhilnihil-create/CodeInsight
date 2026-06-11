#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int p=1000000007;
  vector<int64_t> f(max(n,m)+1,1);
  for(int i=1;i<=max(n,m);i++)
    f.at(i)=f.at(i-1)*i%p;
  cout<<f.at(n)*f.at(m)*(2-min(abs(n-m),2))%p<<endl;
}