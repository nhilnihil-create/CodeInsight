#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define MOD1 1000000007
#define MOD2 998244353
#define LIMIT1 200002
#define LIMIT2 500002
typedef long long ll;
typedef long double ld;
typedef const void cv;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define per(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define zt(a,b) (max((a),(b))-min((a),(b)))
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll nPr(int n,int r){ll i,result=1;rep(i,r){result*=(ll)(n-i);}return result;}
ll nCr(int n,int r){ll i,result=1;if(n<r) return 0;rep(i,min(r,n-r)){result*=(ll)(n-i);result/=(ll)(i+1);}return result;}
#define nHr(n,r) nCr((int)((n)+(r)+1),(int)(r))
#define sankaku(x) (((x)*((x)+1))/2)
int dx[8]={1,0,-1,0,1,-1,-1,1},dy[8]={0,1,0,-1,1,1,-1,-1};
#define downint greater<int>()
#define downchar greater<char>()
#define downstring greater<string>()
void tmpInit(int *c,ll m) {ll i;rep(i,m) c[i]=i;}
ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1){
      res *= a; if(mod>=1) res %= mod;
    }
    a *= a; if(mod>=1) a %= mod;
    n >>= 1;
  }
  return res;
}
void initialize(){
  
}
int main(void){
  initialize();
  ll n,m,i,j,k,result=0,r=0;
  int a[LIMIT2]={0};
  deque<int> b;
  
  cin >> n;
  rep(i,n) cin >> a[i];
  
  rep(i,n){
    if(r%2 == 0) b.push_back(a[i]);
    else b.push_front(a[i]);
    r++;
    r%=2;
  }
  if(r==0){
    while(!b.empty()){
      cout << b.front() << " ";
      b.pop_front();
    }
  }else{
    while(!b.empty()){
      cout << b.back() << " ";
      b.pop_back();
    }
  }
  
  return 0;
}