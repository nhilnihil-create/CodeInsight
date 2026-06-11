#include "bits/stdc++.h"
#define rep(i,n) for(ll i = 0; i < n; i++)
typedef long long ll;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define d_5 100000
#define d9_7 1000000007
#define vll vector<vector<long long>>
#define vl vector<long long>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pf push_front
#define ld long double
#define ll long long
//階乗
 vll comb(51,vl(51,-1));
 ll search(ll n, ll k){
   if(n==k||k==0){
     comb[n][k]=1;
     return 1;
   }
   if(comb[n][k]!=-1){
     return comb[n][k];
   }else{
     comb[n][k]=search(n-1,k-1)+search(n-1,k);
     return comb[n][k];
   }
 }
ll Factrial(ll num){
  if(num==1||num==0){
    return 1;
  }else if(num<0){
    printf("ERROR_minus\n");
    return 0;
  }else{
    return num*Factrial(num-1);
  }
}
 
long long modinv(long long a, long long m) {//modの逆元
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

ll linercomb(ll n,ll k, ll mod){//n,kの線形時間で求める
  ll ans=1;
  if(n/2<k)k=n-k;
  for(ll i=n;i>=n-k+1;i--){
    ans*=i;
    //ans%=mod;
  }
  for(ll i=1;i<=k;i++){
    ans/=i;
  }
  return ans;
}
int main(void){
  ll n,a,b;
  cin>>n>>a>>b;
  vector<long long> v(n);
  rep(i,n)cin>>v[i];
  sort(v.begin(),v.end());
  ld tmp=0;
  for(int i=n-a-1+1;i<n;i++){
    tmp+=v[i];
  }
  ld a2 = a;
  ld tmp2=tmp;
  tmp2/=(long double)a;
  cout<<setprecision(30)<<tmp2<<endl;
  ll num2=0;
  for(int i=n-a-1+1;i<n;i++){
    if(v[n-a-1+1]==v[i]){
      num2++;
    }else{
      break;
    }
  }
  ll num=0;
  for(int i=n-a-1-1+1;i>=0;i--){
    if(v[i]==v[n-a-1-1]){
      num++;
    }else{
      break;
    }
  }
  if(v[n-1]!=v[n-1-a-1]){
    //cout<<num2<<" "<<num<<endl;
    cout<</* num1+numCnum1 */search(num2+num,num2)<<endl;
  }else{
    ll ans=0;
    for(ll i=a;i<=min(num2+num,b);i++){
      ans+=search(num2+num,i);
      //cout<<i<<" "<<num<<" "<<num2<<endl;
      //cout<<search(num2+num,i)<<endl;
    }
    cout<<ans<<endl;
  }
  return 0;
}
