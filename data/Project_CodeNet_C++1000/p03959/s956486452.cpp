#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using pll=pair<ll,ll>;
using graph=vector<vector<int>>;
using wgraph=vector<vector<pll>>;

const ll MOD=1000000007;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const int ex[8]={1,1,0,-1,-1,-1,0,1};
const int ey[8]={0,1,1,1,0,-1,-1,-1};

ll abs1(ll a){
  if(a>=0)return a;
  else return -a;
}

ll pow1(ll a,ll b,ll p=LLONG_MAX){
  ll ret=1;
  while(b!=0){
    if((b&1)==1){
      ret*=a;
    }
    a*=a;
    if(a>=p)a%=p;
    b=b>>1;
  }
  return ret;
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

ll fact(ll n,ll p=MOD){
  if(n<0)return 0;
  int i;
  ll ret=1;
  for(i=0;i<n;i++){
    ret=ret*(i+1);
    if(ret>=p)ret%=p;
  }
  return ret;
}

ll perm(ll n,ll k,ll p=MOD){
  if(n<0 || k<0 || n<k)return 0;
  int i;
  ll ret=1;
  for(i=0;i<k;i++){
    ret=ret*(n-i);
    if(ret>=p)ret%=p;
  }
  return ret;
}

ll binom(ll n,ll k,ll p=MOD){
  if(n<0 || k<0 || n<k)return 0;
  int i;
  ll ret=1,fact=1;
  for(i=0;i<k;i++){
    ret=ret*(n-i);
    fact*=i+1;
    if(ret>=p)ret%=p;
    if(fact>=p)fact%=p;
  }
  return (ret*modRev(fact))%p;
}

void pushHeap(vector<pll>& h,pll n){
  int i=h.size();
  h.push_back(n);
  while(i!=0 && h[(i-1)/2]>h[i]){
    swap(h[i],h[(i-1)/2]);
    i=(i-1)/2;
  }
  h[i]=n;
}

pll popHeap(vector<pll>& h){
  int n=h.size()-1;
  if(n==-1)return pll(0,0);
  ll i;
  pll ret=h[0];
  swap(h[0],h[n]);
  h.pop_back();
  for(i=0;i<n;){
    int j=2*i+1;
    if(j>=n)break;
    if(j!=n-1 && h[j]>h[j+1])j++;
    if(h[i]>h[j]){
      swap(h[i],h[j]);
    }
    i=j;
  }
  return ret;
}

vector<int> ver;
void dfs(const graph &g,int v){
  ver[v]=1;
  for(auto i:g[v]){
    if(ver[i]!=0)continue;
    dfs(g,i);
  }
}

int bis(vector<int> v,int key){
  int left=-1,right=v.size();
  while(abs1(right-left)>1){
    int mid=left+(right-left)/2;
    if(v[mid]<=key)left=mid;
    else right=mid;
  }
  return left;
}

int main(){
  int i,j,cnt=0;
  int n;
  cin>>n;
  int t[n],a[n];
  for(i=0;i<n;i++)cin>>t[i];
  for(i=0;i<n;i++)cin>>a[i];
  int r[n],s[n];
  r[0]=t[0];
  for(i=1;i<n;i++){
    if(t[i-1]<t[i])r[i]=t[i];
    else r[i]=0;
  }
  s[n-1]=a[n-1];
  for(i=n-2;i>=0;i--){
    if(a[i+1]<a[i])s[i]=a[i];
    else s[i]=0;
  }
  for(i=0;i<n;i++){
    if(r[i]!=0 && s[i]!=0 && r[i]!=s[i]){
      cout<<0<<endl;
      return 0;
    }
    if(r[i]>a[i] || s[i]>t[i]){
      cout<<0<<endl;
      return 0;
    }
  }
  ll ans=1;
  for(i=0;i<n;i++){
    if(r[i]==0 && s[i]==0){
      ans*=min(t[i],a[i]);
      if(ans>=MOD)ans%=MOD;
    }
  }
  cout<<ans<<endl;
}
