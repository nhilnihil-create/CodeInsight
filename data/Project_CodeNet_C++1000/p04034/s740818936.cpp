#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,M;
  cin>>N>>M;
  vector<int>x(M),y(M);
  for(int i=0;i<M;i++)cin>>x[i]>>y[i],x[i]--,y[i]--;

  vector<bool>red(N,false);
  red[0]=true;
  vector<int>ball(N,1);

  for(int i=0;i<M;i++){
    if(red[x[i]])red[y[i]]=true;
    ball[x[i]]--;
    ball[y[i]]++;
    if(ball[x[i]]==0)red[x[i]]=false;
  }

  int ans=0;
  for(auto it:red)ans+=it;
  cout<<ans<<endl;

  return 0;
}
