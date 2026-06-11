#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std; using ll=long long; const int INF=1e2; using P=pair<int,int>;

int main() {
  ll h,w,n; cin>>h>>w>>n;
  set<P> s1, s2;
  for(int i=0;i<n;i++) {
    int x,y; cin>>x>>y;
    s1.insert({x,y});
    for(int j=-1;j<=1;j++) {
      for(int k=-1;k<=1;k++) {
        if (2 <= x+j && x+j <= h-1 && 2 <= y+k && y+k <= w-1)
        s2.insert({x+j, y+k});
      }
    }
  }

  ll an[10]={(h-2)*(w-2)-s2.size()};

  for(P x:s2) {
    int sm=0;
    for(int i=x.first-1;i<=x.first+1;i++) {
      for(int j=x.second-1;j<=x.second+1;j++) {
        auto it = s1.find({i,j});
        if (it == s1.end() || *(it) != make_pair(i,j)) continue;
        sm++;
      }
    }
    an[sm]++;
  }
  for(int i=0;i<10;i++) {
    cout<<an[i]<<endl;
  }
}
