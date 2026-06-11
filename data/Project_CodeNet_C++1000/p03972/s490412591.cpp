#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int w,h;
  cin >> w>>h;
  vector<vector<int>>pq(w+h,vector<int>(2));
  vector<int>p(w);
  rep(i,w){
    cin>>p.at(i);
    pq.at(i).at(0)=p.at(i);
    pq.at(i).at(1)=1;
  }
  vector<int>q(h);
  rep(i,h){
    cin>>q.at(i);
    pq.at(i+w).at(0)=q.at(i);
    pq.at(i+w).at(1)=2;
  }
  sort(pq.begin(),pq.end());
  long ans=0;
  long a=w+1;
  long b=h+1;
  rep(i,w+h){
    if(pq.at(i).at(1)==1){
      ans+=pq.at(i).at(0)*b;
      a--;
    }
    else{
      ans+=pq.at(i).at(0)*a;
      b--;
    }
  }
  
  cout<<ans<<endl;
}

