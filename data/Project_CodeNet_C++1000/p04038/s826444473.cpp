#include<iostream>
#include<algorithm>
#include<vector>
#define mod 1000000007
typedef long long ll;

using namespace std;
#define N 2010
#define M 5000010
class Comb{
  public:
  ll fac[M],inv[M],ivf[M];
  void init(){
    fac[0]=ivf[0]=inv[1]=1;
    for(ll i=1;i<M;i++){
      if(i>1)inv[i]=(mod-mod/i*inv[mod%i]%mod)%mod;
      fac[i]=fac[i-1]*i%mod;
      ivf[i]=ivf[i-1]*inv[i]%mod;
    }
  }
  ll qry(ll n,ll k){
    return fac[n]*ivf[n-k]%mod*ivf[k]%mod;
  }
};Comb C;
ll f[N][N],n,k;
int main(){
    C.init();
    cin>>n>>k;
    if(k==1){cout<<1<<endl; return 0;}
    for(ll i=0;i<N;i++)for(ll j=0;j<N;j++)f[i][j]=0; f[0][0]=1;
    for(ll x=0;x<N;x++)for(ll y=0;y<N;y++){
      if(x+1<=y){
	f[x+1][y]=(f[x+1][y]+f[x][y])%mod;
      }
      if(y+1<=n){
	f[x][y+1]=(f[x][y+1]+f[x][y]*C.qry(x+y*(k-1)+k-2,k-2))%mod;
      }
    }
    cout<<f[n][n]*C.fac[n]%mod<<endl;
    return 0;
}
