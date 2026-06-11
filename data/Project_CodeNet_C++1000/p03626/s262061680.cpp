#include<bits/stdc++.h>
#include<bitset>

using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 5e5 + 10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}


vector<int> g[N];
bool viss[N];
int vis[N];

// Normal DFS
void dfs(int curr, int par)
{
  for(auto x: g[curr])
    if(x != par)
      dfs(x, curr);
}

// DFS with visiting status
void dfs1(int curr, int par)
{
  viss[curr] = 1;
  for(auto x: g[curr])
    if(!viss[x])
      dfs1(x, curr);
}

// DFS with strongly connected component
void dfs2(int curr, int par, int num)
{
  vis[curr] = num;
  for(auto x: g[curr])
    if(vis[x] == 0)
      dfs2(x, curr, num);
}

// XOR from 0 to n
ll fxor(ll n)
{
  if(n < 0) return 0;
  if(n % 4 == 3) return 0;
  else if(n % 4 == 0) return n;
  else if(n % 4 == 1) return n^(n-1);
  else if(n%4 == 2) return n^(n-1)^(n-2);
}

// Power in logn with mod 1000000007
llt ppow(llt x, llt y)
{
  llt res = 1;
  while(y > 0){
    if(y&1)
      res = (res * x)%M;
    y = y >> 1;
    x = (x * x)%M;
  }
  return res;
}

// Factorial with dp
llt factdp[N];
llt fact(llt x)
{
  if(x == 0) return 1;
  if(x == 1) return 1;
  if(factdp[x] != 0) return factdp[x];
  return factdp[x] = (x*fact(x-1))%M;
}
// Combination
ll modcomb(ll n, ll r)
{
  if(n < r) return 0;
  ll res = fact(n);
  (res *= ppow(fact(r), M-2)) %= M;
  (res *= ppow(fact(n-r), M-2)) %= M;
  return res;
}

//GCD and LCM
llt gcd(llt x, llt y)
{
  if(y == 0) return x;
  return gcd(y, x%y);
}
llt lcm(llt x, llt y)
{
  return (x / gcd(x, y)) * y;
}

// String return to base b
string ansConv ="";
void convert10tob(llt N, int b)
{
     if (N == 0)
        return;
     int x = N % b;
     N /= b;
     if (x < 0)
        N += 1;
     convert10tob(N, b);
     ansConv += to_string(x);
     return;
}

// Convert string to num wiht base b
llt convertstrtob(string a, int b)
{
  llt aa = 0;
  llt mul = 1;
  for(int i=a.length()-1; i>=0; i--)
  {
    int curr = a[i] - '0';
    aa += (curr * mul);
    mul *= b;
  }
  return aa;
}

// Union Find
// Find()
int parent[N], ran[N];
int find(int x)
{
    if(parent[x]==x)return x;
    else return parent[x]=find(parent[x]);
}
// Union()
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;

    if(ran[x]<ran[y])
        parent[x]=y;
    else{
        parent[y]=x;
        if(ran[x]==ran[y])ran[x]++;
    }
}

// Main Code


int main()
{
  int n;
  cin>>n;
  string u, d;
  cin>>u>>d;
  ll ans = 0;
  bool f = true;
  char curr, last;
  int i;
  if(u[0] == d[0])
  {
   curr = 'v';
   ans = 3;
   i = 1;
  }
  else
  {
    curr = 'h';
    ans = 6;
    i = 2;
  }
  last = curr;
  while(i < n)
  {
    if(u[i] == d[i])
    {
      curr = 'v';
      i++;
    }
    else
    {
      curr = 'h';
      i += 2;
    }
    if(last == 'v')
    {
      ans = (ans * 2) % M;
    }
    else
    {
      if(curr == 'h')
      {
        ans = (ans * 3) % M;
      }
    }
    last = curr;
  }
  cout<<ans<<endl;
  return 0;
}
