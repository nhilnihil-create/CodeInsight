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

struct UnionFind {
  vector<int> data;

  UnionFind(int n){
    data.resize(n+1);
    fill(data.begin(), data.end(), -1);
  }

  int root(int x){
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }

  void unite(int x, int y){
    int rx=root(x);
    int ry=root(y);

    if(rx!=ry){
      if(data[ry] < data[rx])swap(rx, ry);

      data[rx]+=data[ry];
      data[ry]=rx;
    }
  }

  bool same(int x, int y){
    return root(x)==root(y);
  }

  int size(int x){
    return -data[root(x)];
  }
};

int main(){
  int w,h;cin>>w>>h;
  vector<pll>pq(w+h);
  rep(i, w+h){
    cin>>pq[i].first;
    pq[i].second = i;
  }
  sort(pq.begin(), pq.end());

  UnionFind uf(w+h);

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
//    cout<<result<<' '<<p.first<<':'<<cw<<' '<<ch<<endl;
  }

  cout<<result<<endl;

  return 0;

  cout<<"###"<<endl;
  for(auto pp:pq)cout<<pp.first<<' '<<pp.second<<endl;

  return 0;
}

