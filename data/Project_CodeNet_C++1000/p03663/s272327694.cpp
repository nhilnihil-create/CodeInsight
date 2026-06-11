#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

ll N;
bool test(ll n){
  string NN=to_string(N);
  string nn=to_string(n);
  bool flag=(n<=N&&nn<=NN);
  bool flag2=(n>N&&nn>NN);
  return (flag|flag2);
}

bool solve(ll x){
  //return test(x);
  cout<<"? "<<x<<endl;
  char c; cin>>c;
  return (c=='Y');
}

ll fact[12];
 
int main(){
  fact[0]=1;
  rep(i,11) fact[i+1]=fact[i]*10;
  //cin>>N;
  ll n=0;
  int keta=0;
  for(ll i=1;i<=1e10;i*=10){
    if(solve(i)) keta++;
    else break;
  }
  if(keta!=11){
    int first=1;
    rep(aaa,keta-1){
      int ok=first, ng=10;
      while(abs(ok-ng)>1){
        int mid=(ok+ng)/2;
        if(solve(n*10+mid)) ok=mid;
        else ng=mid;
      }
      n=n*10+ok;
      first=0;
    }
    int ok=0, ng=10;
    while(abs(ok-ng)>1){
      int mid=(ok+ng)/2;
      if(!solve(n*100+mid*10)) ok=mid;
      else ng=mid;
    }
    n=n*10+ng;
  }else{
    ll x=0;
    rep(i,11) x=x*10+9;
    keta=11;
    rep(i,11){
      if(solve(x)) keta--, x/=10;
      else break;
    }
    n=fact[keta];
  }
  cout<<"! "<<n<<endl;
  return 0;
}