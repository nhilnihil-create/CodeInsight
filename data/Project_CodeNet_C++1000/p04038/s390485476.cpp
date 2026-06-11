#include <bits/stdc++.h>
#define C(n,m) (1ll*ml[n]*ny[m]%mo*ny[(n)-(m)]%mo)
#define cal(a,b) ((a+=b)%=mo)
using namespace std;
const int mo=1e9+7;
int f[2050][2050],ml[4000050],ny[4000050];
int fap(int a,int b){
  int s=1;
  while(b){
    if (b&1) s=1ll*a*s%mo;
    b>>=1,a=1ll*a*a%mo;
  }
  return s;
}
int main(){
  int n,k; cin>>n>>k;
  if (k==1) return puts("1"),0;
  ml[0]=ny[0]=1;
  for (int i=1; i<=n*k; ++i) ml[i]=1ll*ml[i-1]*i%mo;
  ny[n*k]=fap(ml[n*k],mo-2);
  for (int i=n*k-1; i; --i) ny[i]=1ll*(i+1)*ny[i+1]%mo;
  f[0][0]=1;
  for (int i=0; i<n; ++i)
    for (int j=0; j<=i; ++j){
      cal(f[i+1][j],1ll*f[i][j]*C((i+1)*(k-1)+j-1,k-2)%mo);
      if (j!=i) cal(f[i][j+1],f[i][j]);
    }
  for (int i=0; i<n; ++i) cal(f[n][i+1],f[n][i]);
  for (int i=1; i<=n; ++i) f[n][n]=1ll*f[n][n]*i%mo;
  cout<<f[n][n];
  return 0;
}
