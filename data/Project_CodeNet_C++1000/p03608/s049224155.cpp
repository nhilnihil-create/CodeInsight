#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_V = 200;
const ll inf = 100100100100100100;
ll V,D[MAX_V][MAX_V];
void WarshallFloyd(){
  ll i,j,k;
  for(i=0;i<V;i++) D[i][i] = 0;
  for(k=0;k<V;k++){
    for(i=0;i<V;i++){
      for(j=0;j<V;j++) D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
    }
  }
}
int main(){
  ll E,R,i,a,b,c,ans = inf,now;scanf("%lld%lld%lld",&V,&E,&R);
  ll r[R];
  for(i=0;i<V;i++) fill(D[i],D[i]+V,inf);
  for(i=0;i<R;i++){
    scanf("%lld",&r[i]);r[i]--;
  }
  sort(r,r+R);
  for(i=0;i<E;i++){
    scanf("%lld%lld%lld",&a,&b,&c);a--;b--;
    D[a][b] = D[b][a] = c;
  }
  WarshallFloyd();
  do{
    now = 0;
    for(i=0;i<R-1;i++) now += D[r[i]][r[i+1]];
    ans = min(ans,now);
  }while(next_permutation(r,r+R));
  printf("%lld\n",ans);
}