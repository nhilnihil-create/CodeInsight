#include <bits/stdc++.h>
using namespace std;
template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
#define int long long

signed main(){
  int n,l;cin>>n>>l;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  int a=-1;
  for(int i=1;i<n;i++)if(v[i]+v[i-1]>=l)a=i;
  if(a<0)fin("Impossible");
  cout<<"Possible"<<endl;
  for(int i=1;i<a;i++)cout<<i<<endl;
  for(int i=n-1;i>=a;i--)cout<<i<<endl;
}
