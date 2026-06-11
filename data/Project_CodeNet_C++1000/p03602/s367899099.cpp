#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 100100100100100100;
struct edge{
  ll cost,u,v;
  bool operator<(const edge &o)const{return cost < o.cost;}
  bool operator>(const edge &o)const{return cost > o.cost;}
};
int main(){
  ll n,i,j,k,c,l,r,ans = 0,MIN;bool noneed;
  scanf("%lld",&n);
  ll D[n][n];vector<edge> V;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) scanf("%lld",&D[i][j]);
  }
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++) V.push_back(edge{D[i][j],i,j});
  }
  sort(V.begin(),V.end());
  for(i=0;i<V.size();i++){
    c = V[i].cost;l = V[i].u;r = V[i].v;
    MIN = inf;noneed = false;
    for(j=0;j<n;j++){
      MIN = min(MIN,D[l][j]+D[j][r]);
      if(j != l && j != r && c == D[l][j]+D[j][r]) noneed = true;
    }
    if(MIN < c){
      printf("-1\n");return 0;
    }
    if(!noneed) ans += c;
  }
  printf("%lld\n",ans);
  return 0;
}