#include<iostream>
#include<algorithm> // sort,reverse,min,lower_bound
using namespace std;
#define df 0

int lg(int n){
  int cnt=1;
  while(n){
    cnt++;
    n/=2;
  }
  return cnt;
}

int main(){
  if(df) printf("*debug mode*\n");
  int n; cin >> n;
  int x[n];
  for(auto& a:x){
    cin >> a;
  }
  int l,q; cin >> l >> q;

  int lmax=lg(n);
  int dbl[n][lmax];
  for(int i=0;i<n;i++){
    dbl[i][0]=upper_bound(x,x+n,x[i]+l)-x-1;
    if(df)printf("[%d] ",dbl[i][0]);
  }
  for(int j=1;j<lmax;j++){
    if(df)printf("\n");
    for(int i=0;i<n;i++){
      dbl[i][j]=dbl[dbl[i][j-1]][j-1];
      if(df)printf("[%d] ",dbl[i][j]);
    }
  }

  for(int i=0;i<q;i++){
    int a, b; cin >> a >> b; a--; b--; if(a>b)swap(a,b);
    int day=0;
    for(int i=lmax-1;i>=0;i--){
      if(dbl[a][i]>=b)continue;
      day+=1<<i;
      a=dbl[a][i];
    }
    while(a<b){
      a=dbl[a][0];
      day++;
    }
    printf("%d\n",day);
  }
  
  if(df)printf("%d",lg(100000));
}

/// confirm df==0 ///
