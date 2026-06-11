#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;

const ll MOD=1000000007;

ll abs1(ll a){
  if(a>=0)return a;
  else return -a;
}

ll pow1(ll a,ll b){
  ll p=1;
  for(int i=0;i<b;i++){
    p*=a;
  }
  return p;
}

int digit(ll a,ll b){
  int i=0;
  while(a!=0){
    a/=b;
    i++;
  }
  return i;
}

ll gcd1(ll a,ll b){
  if(a==0 && b==0)return 0;
  ll n;
  while(a%b!=0){
    n=a%b;
    a=b;
    b=n;
  }
  return b;
}

ll solveLinear(ll n,ll m,ll c){
  if(n==0 && m==0)return 0;
  ll a[100],b[100];
  a[0]=n;b[0]=m;
  int i=1;
  while(b[i-1]!=0){
    a[i]=b[i-1];
    b[i]=a[i-1]%b[i-1];
    i++;
  }
  n=i;
  if(c%a[n-1]!=0){
    return 0;
  }
  ll x=c/a[n-1],y=0;
  for(i=1;i<n;i++){
    ll cnt=x;
    x=y;
    y=cnt-(a[n-i-1]/b[n-i-1])*y;
  }
  return x;
}

ll modRev(ll a,ll p=MOD){
  a%=p;
  ll n=solveLinear(a,p,1);
  n%=p;
  if(n<0)return n+p;
  return n;
}

ll binom1(ll n,ll k,ll p=MOD){
  if(n<0 || k<0 || n<k)return 0;
  int i;
  ll ret=1;
  for(i=0;i<k;i++){
    ret=ret*(n-i)/(i+1);
    if(ret>=p)ret%=p;
  }
  return ret;
}

int main(){
  int i,j,k,cnt=0;
  string s;
  cin>>s;
  int n=s.size();
  for(i=0;i<26;i++){
    for(j=1;j<n;j++){
      if(s[j-1]=='a'+i && s[j]=='a'+i){
        cout<<j<<" "<<j+1<<endl;
        return 0;
      }
    }
    for(j=2;j<n;j++){
      if(s[j-2]=='a'+i && s[j]=='a'+i){
        cout<<j-1<<" "<<j+1<<endl;
        return 0;
      }
    }
  }
  cout<<-1<<" "<<-1<<endl;
}
