#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=1e9;
const long long LINF=1e18;
#define int long long
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
int pw(int n,int k){
  if(k<0)return pw(n,k+MOD-1);
  int res=1;
  while(k){
    if(k&1)res*=n;//res%=MOD;
    n*=n;//n%=MOD;
    k>>=1;
  }
  return res;
}
int d[123456][35];//d[i][j]:iから2^j日で行けるところ
//main
signed main(){
  int N,L,Q;cin>>N;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  cin>>L>>Q;
  std::vector<int> a(Q),b(Q);
  for(int i=0;i<Q;i++){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
    if(a[i]>b[i])swap(a[i],b[i]);
  }
  for(int i=0;i<N;i++){
    int l=i+1,r=N;
    while(r-l>1){
      int m=(r+l)>>1;
      if(v[m]<=v[i]+L)l=m;
      else r=m;
    }
    d[i][0]=l;
  }
  for(int j=0;j<35;j++)d[N][j]=N;
  for(int j=1;j<35;j++)
    for(int i=0;i<N;i++)
      d[i][j]=d[d[i][j-1]][j-1];
  for(int i=0;i<Q;i++){
    int ans=0;
    int s=a[i],g=b[i];
    for(int j=34;j>=0;j--){
      if(d[s][j]<=g){
        ans+=pw(2,j);
        s=d[s][j];
      }
    }
    if(s!=g)ans++;
    cout<<ans<<endl;
  }
}
