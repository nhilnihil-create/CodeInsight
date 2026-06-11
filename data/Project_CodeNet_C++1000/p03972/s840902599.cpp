#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long w,h,o,t,ans=0;
  cin >> w >> h;
  o=h+1;
  t=w+1;
  vector<pair<long,long>> pq(w+h,{0,0});
  for(long i=0;i<w;i++) {
    cin >> pq[i].first;
    pq[i].second=1;
  }
  for(long i=0;i<h;i++) {
    cin >> pq[w+i].first;
    pq[w+i].second=2;
  }
  sort(pq.begin(),pq.end());
  for(long i=0;i<h+w;i++) {
    if(pq[i].second==1) {
      ans+=pq[i].first*o;
      t--;
    } else {
      ans+=pq[i].first*t;
      o--;
    }
  }
  
  cout << ans << endl;
}