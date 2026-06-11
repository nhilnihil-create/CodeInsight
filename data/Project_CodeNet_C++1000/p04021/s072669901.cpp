#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); 

  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  vector<int>B=A;
  sort(rng(B));
  map<int,int>m;
  for(int i=0;i<N;i++){
    m[B[i]]=i;
  }
  int ans=0;
  for(int i=0;i<N;i++){
    int d=abs(m[A[i]]-i);
    if(d%2)ans++;
  }
  cout<<ans/2<<endl;
  return 0;
}
