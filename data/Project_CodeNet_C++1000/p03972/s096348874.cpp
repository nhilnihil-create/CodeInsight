#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int w,h;cin>>w>>h;
  vector<pll>pq(w+h);
  rep(i, w+h){
    cin>>pq[i].first;
    pq[i].second = i;
  }
  sort(pq.begin(), pq.end());

  ll cw=w+1, ch=h+1;
  ll result = 0;
  for(auto p: pq){
    if(p.second >= w){
      result += p.first*cw;
      ch--;
    }else{
      result += p.first*ch;
      cw--;
    }
  }

  cout<<result<<endl;

  return 0;
}

