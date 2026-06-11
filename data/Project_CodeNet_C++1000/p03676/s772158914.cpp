#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

#define MOD 1000000007

// nCk = n!/(n-k)!k!

int main(){
  int n;
  cin >> n;
  vector<int> a(n+1);
  vector<LL> factorial(n+1),gyaku(n+1);
  vector<int> appeared(n+1,-1);
  factorial[0]=1;
  for(int i=1;i<=n;i++){
    factorial[i]=i*factorial[i-1]%MOD;
  }
  LL tmp=factorial[n];
  gyaku[n]=1;
  for(int i=0;i<30;i++){
    if((MOD-2)&(1<<i)){
      gyaku[n]=gyaku[n]*tmp%MOD;
    }
    tmp=tmp*tmp%MOD;
  }
  for(int i=n-1;i>=1;i--){
    gyaku[i]=(i+1)*gyaku[i+1]%MOD;
  }
  gyaku[0]=1;
  // for(int i=1;i<=n;i++){
  //   cout << i << ":" << factorial[i] << " " << gyaku[i] << " " << factorial[i]*gyaku[i]%MOD << endl;
  // }
  int hidari,migi;
  for(int i=0;i<n+1;i++){
    cin >> a[i];
    if(appeared[a[i]]>=0){
      hidari=appeared[a[i]];
      migi=i;
    }
    appeared[a[i]]=i;
  }
  cout << n << endl;
  LL ans;
  if(migi-hidari>1){
    for(int k=2;k<=n-1;k++){
      ans=factorial[n-1]*gyaku[n-k-1]%MOD*gyaku[k]%MOD;
        if(n-migi+hidari<k-1) ans=(ans+2*factorial[n-1]%MOD*gyaku[n-k]%MOD*gyaku[k-1]%MOD)%MOD;
        else ans=(ans+2*factorial[n-1]%MOD*gyaku[n-k]%MOD*gyaku[k-1]%MOD-factorial[n-migi+hidari]*gyaku[n-migi+hidari-k+1]%MOD*gyaku[k-1]%MOD)%MOD;
      ans=(ans+factorial[n-1]*gyaku[n-k+1]%MOD*gyaku[k-2]%MOD)%MOD;
      ans=(ans+MOD)%MOD;
      cout << ans << endl;
    }
    if(n>1){
      int k=n;
      ans=0;
        if(n-migi+hidari<k-1) ans=(ans+2*factorial[n-1]%MOD*gyaku[n-k]%MOD*gyaku[k-1]%MOD)%MOD;
        else ans=(ans+2*factorial[n-1]%MOD*gyaku[n-k]%MOD*gyaku[k-1]%MOD-factorial[n-migi+hidari]*gyaku[n-migi+hidari-k+1]%MOD*gyaku[k-1]%MOD)%MOD;
      ans=(ans+factorial[n-1]*gyaku[n-k+1]%MOD*gyaku[k-2]%MOD)%MOD;
      ans=(ans+MOD)%MOD;
      cout << ans << endl;
    }
  }else{
    for(int k=2;k<=n;k++){
      ans=factorial[n]*gyaku[n-k]%MOD*gyaku[k]%MOD;
      ans=(ans+factorial[n-1]*gyaku[n-k+1]%MOD*gyaku[k-2]%MOD)%MOD;
      cout << ans << endl;
    }
  }
  cout << 1 << endl;
  return 0;
}
