#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()
#define ones(a) __builtin_popcount(a)

const int N = (int)2e5 + 9;

struct Union{
  int siz[N];
  int nex[N];
  Union(){
    for(int i = 0;i < N; i ++ )
      siz[i] = 1, nex[i] = i;
  }
  int move(int a){
    while(nex[a] != a)
      a = nex[a];
    return a;
  }
  void unite(int a, int b){
    a = move(a);
    b = move(b);
    if(a == b)  
      return;
    if(a > b)
      swap(a, b);
    nex[a] = b;
    siz[b] += siz[a];
  }
};

map<pii, int> cnt;

int main(){
  fastIO;
  Union *road = new Union();
  Union *rail = new Union();
  int n,k,l;
  cin >> n >> k >> l;
  int u, v;
  for(int i = 0;i < k;i ++ ){
    cin >> u >> v;
    road->unite(u, v);
  }
  for(int i = 0;i < l;i ++ ){
    cin >> u >> v;
    rail->unite(u, v);
  }
  int Road[n + 1], Rail[n + 1];
  for(int i = 1; i <= n;i ++ ){
    Road[i] = road->move(i);
    Rail[i] = rail->move(i);
    cnt[mp(Road[i], Rail[i])] ++ ;
  }
  for(int i = 1;i <= n; i ++ ){
    cout << cnt[mp(Road[i], Rail[i])] << " ";
  }
  return 0;
}
