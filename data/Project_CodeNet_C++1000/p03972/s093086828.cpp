#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);++i)
#define rrep(i,n) for(int (i)=(n)-1;(i)>=0;--i)
#define rep1(i,n) for(int (i)=1;(i)<=(n);++i)
#define rrep1(i,n) for(int (i)=(n);(i)>=1;--i)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int,int> P;
typedef pair<long long,long long> LP;
typedef double db;
using namespace std;

ll W,H;
LP p[200000];
ll ans = 0;
ll cnt[2] = {0,0};
ll C = 0;
priority_queue<LP,vector<LP>,greater<LP> > q;

int main()
{
  cin>>W>>H;
  ll E[2];
  E[0] = W;
  E[1] = H;
  rep(i,W){
    cin>>p[i].fr;
    p[i].sc = 0;
    q.push(p[i]);
  }
  rep(i,H){
    cin>>p[W+i].fr;
    p[W+i].sc = 1;
    q.push(p[W+i]);
  }
  while(C<(W+1)*(H+1)-1){
    LP e = q.top();
    q.pop();
    ll s = E[!e.sc] + 1LL - cnt[!e.sc];
    ans += s*e.fr;
    C += s;
    cnt[e.sc]++;
  }
  cout<<ans<<endl;
}
