#include <bits/stdc++.h>
using namespace std;

#define All(a) (a).begin(),(a).end()
#define ll long long int
ll A[51][51][2501];

int a;
ll ans=0;

void solve(){
  int n;
  scanf("%d %d",&n,&a);
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&v[i]);
  }
  
  A[0][0][0]=1;
  
  for (int i = 0; i < n; i++)
  {
    for (int k = 0; k <=50*n; k++)
    {
      for (int j = 0; j <n; j++)
      {
        //printf("%lld ",A[i][j][k]);;
        if(A[i][j][k]==0)continue;
        A[i+1][j][k]+=A[i][j][k];
        A[i+1][j+1][k+v[i]]+=A[i][j][k];
      }
      //printf("\n");
    }
    //printf("\n");
  }
  
  for (int k = 1; k <= n; k++)
  {
    ans+=A[n][k][a*k];
  }
  
  printf("%lld",ans);
}
int main(){
  /*
  int q;
  scanf("%d",&q);
  while(--q)solve();
  */
  solve();

  return 0;
}