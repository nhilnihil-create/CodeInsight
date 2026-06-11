#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=1e9;
const long long LINF=1e18;
#define int long long
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
//main
signed main(){
  int N;cin>>N;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  sort(v.begin(),v.end());
  map<int,int> m;
  for(int i=0;i<N;i++)m[v[i]]++;
  if(v[N-1]&1){
    for(int i=v[N-1];i>v[N-1]/2;i--)if(m[i]<2)fin("Impossible");
    if(m[v[N-1]/2+1]>2)fin("Impossible");
    for(int i=v[N-1]/2;i>=0;i--)if(m[i])fin("Impossible");
    fin("Possible");
  }
  for(int i=v[N-1];i>v[N-1]/2;i--)if(m[i]<2)fin("Impossible");
  if(m[v[N-1]/2]!=1)fin("Impossible");
  for(int i=m[v[N-1]/2-1];i>=0;i--)if(m[i])fin("Impossible");
  fin("Possible");
}
