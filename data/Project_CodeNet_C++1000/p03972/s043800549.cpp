#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define int ll

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int W,H;
  cin>>W>>H;
  priority_queue<int,vector<int>,greater<int>>p,q;
  for(int i=0;i<W;i++){
    int x;cin>>x;
    p.push(x);
  }
  for(int i=0;i<H;i++){
    int x;cin>>x;
    q.push(x);
  }
  p.push(INF);
  q.push(INF);
  int a=W+1;
  int b=H+1;
  int ans=0;
  for(int i=0;i<H+W;i++){
    int x=p.top();
    int y=q.top();
    if(x==INF&&y==INF)break;
    if(x<y)ans+=x*b,a--,p.pop();
    else ans+=y*a,b--,q.pop();
  }
  cout<<ans<<endl;
  return 0;
}
