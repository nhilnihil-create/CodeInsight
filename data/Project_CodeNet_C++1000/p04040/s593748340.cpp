#include <bits/stdc++.h>
using namespace std;

const long long md = 1e9+7;
const long long maxn = 300100;
long long fac[maxn], inv[maxn];

long long powd(long long x, long long y){
  long long res = 1;
  while(y){
    if(y&1) res=res*x%md;
    x=x*x%md;
    y>>=1;
  }
  return res;
}

void csh(){
  fac[0]=1;
  for (int i=1; i<maxn; i++){
    fac[i] = fac[i-1]*i%md;
  }
  inv[300000] = powd(fac[300000],md-2);
  for (int i=300000; i>0; i--){
    inv[i-1] = inv[i]*i%md;
  }
}

long long C(long long x, long long y){
  if (y<0||y>x) return 0;
  else return fac[x]*inv[y]%md*inv[x-y]%md;
}

int main(){
  long long H, W, A, B;
  cin >> H >> W >> A >> B;
  csh();
  long long ans = C(H+W-2,W-1);
  long long fob = 0;
  for (int i=0; i<B; i++){
    fob += C(H-A+i,i)*C(A-1+W-1-i,A-1)%md - C(H-A+i-1,i-1)*C(A-1+W-1-i,A-1)%md + md;
    fob %= md;
  }
  cout << (ans-fob+md)%md << endl;
}
