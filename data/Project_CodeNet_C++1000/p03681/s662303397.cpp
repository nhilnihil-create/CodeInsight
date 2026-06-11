#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define rf(i,n,a) for(int i=n ; i>=a ; i--)
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;

const int inf = 1e9;
const int inf64 = 1e18;
const int MOD = inf + 7;
const int N = 1e5 + 5;
int fact[N], invfact[N];

int pow(int a, int b, int m)
{
   int ans=1;
   while(b)
   {
      if(b&1)
         ans=(ans*a)%m;
      b/=2;
      a=(a*a)%m;
   }
   return ans;
}

int modinv(int k)
{
   return pow(k, MOD-2, MOD);
}

void precompute()
{
   fact[0]=fact[1]=1;
   for(int i=2;i<N;i++)
   {
      fact[i]=fact[i-1]*i;
      fact[i]%=MOD;
   }
   invfact[N-1]=modinv(fact[N-1]);
   for(int i=N-2;i>=0;i--)
   {
      invfact[i]=invfact[i+1]*(i+1);
      invfact[i]%=MOD;
   }
}

int nCr(int x, int y)
{
   if(y>x)
      return 0;
   int num=fact[x];
   num*=invfact[y];
   num%=MOD;
   num*=invfact[x-y];
   num%=MOD;
   return num;
}

int32_t main(){
   fast;
   precompute();
   int n,m;
   cin >> n >> m;
   int ans = 0;
   if(abs(n-m) <= 1) ans = (fact[n] * fact[m] * ((n == m) + 1))%MOD;
   cout << ans << "\n";
}