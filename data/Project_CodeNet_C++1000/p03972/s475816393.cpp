#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll w,h,adx,ady,sum=0;
  vector<P> pq;
  cin >> w >> h;
  ll p[w],q[h];
  adx=h+1;
  ady=w+1;
  for(int i=0;i<w;i++){
    cin >> p[i];
    pq.push_back(P(p[i],0));
  }
  for(int i=0;i<h;i++){
    cin >> q[i];
    pq.push_back(P(q[i],1));
  }
  sort(pq.begin(),pq.end());
  for(int i=0;i<pq.size();i++){
    if(pq[i].second==0){
      sum += pq[i].first*adx;
      ady = max(ady-1,(ll)0);
    }else{
      sum += pq[i].first*ady;
      adx = max(adx-1,(ll)0);
    }
  }
  cout << sum<<endl;
}
