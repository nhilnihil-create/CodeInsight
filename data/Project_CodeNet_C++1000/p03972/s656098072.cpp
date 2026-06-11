#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
vector<int> par(1000000);//それぞれの頂点の親,最大値をsizeにする
vector<int> dis(1000000);//ランク
int n;
class union_find{
  public:
  void init(){
    for(int i = 0;i < n;i++){
      par[i] = i;//最初、親は自分自身とする
      dis[i] = 0;
    }
  }
  //木の根を求める
  int root(int x){
    if(par[x] == x){
      return x;
    }
    else{
      return par[x] = root(par[x]);
    }
  }
  //xとyが同じ集合に属すか否か
  bool same(int x,int y){
    //cout << x << " " << y << endl;
    return (root(x) == root(y));
  }
  //xとyの属する集合を併合
  void unite(int x,int y){
    x = root(x);
    y = root(y);
    if(x == y)return;
    if(dis[x] < dis[y]){
      par[x] = y;
    }
    else{
      par[y] = x;
      if(dis[x] == dis[y])dis[x]++;
    }
  }
};

//union_find tree;
//tree.init() //これで初期化
//tree.unite(a,b) //aとbのグループを併合
//tree.same(a,b) //aとbが同じグループか(trueかfalse)

int main(){
  ll w,h;
  cin >> w >> h;
  n = w + h + 2;
  vector<pair<ll,ll>> edge(w + h);
  for(int i = 0;i < w;i++)cin >> edge[i].first,edge[i].second = i;
  for(int i = 0;i < h;i++)cin >> edge[w + i].first,edge[w + i].second = i + w;
  sort(edge.begin(),edge.end());
  union_find tree;
  tree.init();
  ll a = h + 1;
  ll b = w + 1;
  ll res = 0;
  for(int i = 0;i < w + h;i++){
    if(tree.same(edge[i].second,edge[i].second + 1))continue;
    else if(edge[i].second >= w){//h方向
      res += b * edge[i].first;
      a--;
      tree.unite(edge[i].second,edge[i].second + 1);
    }
    else{//w方向
      res += a * edge[i].first;
      b--;
      tree.unite(edge[i].second,edge[i].second + 1);
    }
    //cout << i << " " << edge[i].first << " " << res << endl;
  }
  cout << res << endl;
}