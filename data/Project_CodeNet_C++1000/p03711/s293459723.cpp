#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
////////////////////////////////////unionfind

int par[100010];//親
int rnk[100010];//ランク

void init(int n){//初期化
  for(int i=0;i<n;i++){
     par[i]=i;
     rnk[i]=0;
  }
}

int find(int x){//親を求める
  if(par[x]==x) return x;
  return par[x]=find(par[x]);
}

void unite(int x,int y){//union
  x=find(x);
  y=find(y);
  if(x==y)return;
  if(rnk[x]<rnk[y]){//rankが小さい方にくっつける
    par[x]=y;
  }
  else{
   par[y]=x;
    if(rnk[x]==rnk[y])rnk[x]++;//rankが同じ時は1増やす
  }
}

bool same(int x,int y){
 return find(x)==find(y); 
}
int main(){
 init(13);
  int a,b;
  cin>>a>>b;
  unite(4,6);unite(6,9);unite(9,11);
  unite(1,3);unite(3,5);unite(5,7);unite(7,8);unite(8,10);unite(10,12);
  Yes(same(a,b));
}