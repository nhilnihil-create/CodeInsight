
#include <bits/stdc++.h>
#include <math.h>
#include <cmath>

using namespace std;
using ll =long long;
using vi = vector<int>; 
using vvi = vector<vi>; 
using vl = vector<ll>; 
using vvl = vector<vl>; 
using vs = vector<string>;
using vvs = vector<vs>; 
using vc = vector<char>;
using vvc = vector<vc>; 
using vb = vector<bool>;
using vvb = vector<vb>; 

#define rep(i,n); for( int i =0; i < n ; i ++)
#define all(a) a.begin(),a.end()
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define f(i,a,b) for(int i=a;i<b;i++)
#define pri(a)  printf("%.14lf\n",a);
#define MOD 1000000007
typedef pair<int, int> P;
bool is_int_lround(double x){
  return std::lround(x)==x;
}
ll keta(ll x){
  ll n=0;
  while(x>0){
    x /=10 ;
    n ++;
  }
  return n;
}

ll conbi(int n,int m){
  
  cin>>n>>m;
  vector<ll> a(100);
  a[0] =1;
  for(int i=0;i<14;i++){
    a[i+1]=a[i]*(i+1);
  }
  return a[n] /(a[m] *a[n-m]);
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;//繰り返し二乗法
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
ll kaijo(ll x){
  ll z=1;
  while(x>0){
    z *=x;
    z %=MOD;
    x--;
  }
  return z;
}
ll yakusu_num(ll n){
  vl yakusu(n+1,1);
  for(ll i=2;i*i<=n;i++){ 
    while(n%i==0){
      n /=i;
      yakusu[i]++;
    }
  }
  if(n!=1)yakusu[n]++;
  ll num=1;
  for(ll i=0;i <=n;i++){
    num*=yakusu[i];
  }
  return num;
}


//cout<<""<<endl;
int main(){
  ll N,K;cin>>N>>K;vl a(N);
  rep(i,N){
    cin>>a[i];
  }
  vl b(N);
  
  vl d(N);d[0]=a[0];
  rep(i,N-1){
    d[i+1]=max(d[i],a[i+1]);
  }
  ll ans=100000000000;
  for(int tmp ; tmp<(1<<N-1);tmp++){
    bitset<14> s(tmp);
    ll cnt=0;
    b =d;
    if(s.count()>=K-1){
      for(int i=0;i<N-1;i++){
        b[i+1]=max(b[i],b[i+1]);
        if(s.test(i)){
          if(b[i]>a[i+1]){
            cnt+=b[i]-a[i+1]+1;
            b[i+1] =b[i]+1;
          }
          else if(b[i]<a[i+1]){
            b[i+1]=a[i+1];
          }
          else if(b[i]==a[i+1]){
            cnt+=1;
            b[i+1]=b[i]+1;
          }
        }
      }
      ans =min(cnt,ans);
    }
    else continue;
  }
  cout<<ans<<endl;
}
