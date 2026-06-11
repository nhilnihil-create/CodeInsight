/* ----------------------- reclone_rk --------------------------------------------*/ 
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod=1e9+7;

#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define prq priority_queue<int>
#define prqp priority_queue<pair<int,int>>
#define vtr vector<int>
#define INF INT_MAX
#define NINF INT_MIN
#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pvtr vector<pair<int,int>>
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)

int gcd(int a, int b){ if(a == 0) return b; return gcd(b%a, a);}
int MOD(int n){ return ((n%mod)+mod)%mod;}
int power(int a,int b){ if(b==0)return 1LL;int s=power(a,b/2LL);s*=s;s%=mod;if(b&1LL)return (s*a)%mod;return s;}
int inv(int a){return power(a,mod-2);}
int nCr(int n,int r){if(r>n)return 0LL;if(n-r<r)r=n-r;int ans=1;for(int i=0;i<r;i++){ans*=(n-i);ans=MOD(ans);ans*=inv(i+1);ans=MOD(ans);}return ans;}

const double pi = 3.14159265358979323846;
signed main()
{   
   int n;
   cin>>n;
   vector<int>a(n);
   int sum = 0;
   for(int i=0; i<n; i++)
   {
      cin>>a[i];
      sum += a[i];
   }
   if(sum%n == 0)
   {
      int ans = sum/n;
      int val = 0;
      for(int i=0; i<n; i++)
      {
         val += abs(ans - a[i]) * abs(ans - a[i]);
      }
      cout<<val<<endl;
   }
   else
   {
      int ans1 = sum/n;
      int ans2 = ans1 + 1;
      int val1 = 0;
      int val2 = 0;
      for(int i=0; i<n; i++)
      {
         val1 += abs(ans1 - a[i]) * abs(ans1 - a[i]);
         val2 += abs(ans2 - a[i]) * abs(ans2 - a[i]);

         
      }
      cout<<min(val1, val2)<<endl;
   }
	return 0;
}