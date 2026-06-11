#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, (b), sizeof(a))
#define fore(i,a) for(int i=0;i<a;i++)
#define fore1(i,j,a) for(int i=j;i<a;i++)
#define print(ar) for(int i=0;i<ar.size();i++)cout<<ar[i]<<" ";
#define END cout<<'\n'
const double pi=acos(-1.0);
 
typedef pair<int, int> PII;
 
typedef vector<long long int> VI;
 
typedef vector<string> VS;
 
typedef vector<PII> VII;
 
typedef vector<VI> VVI;
 
typedef map<int,int> MPII;
 
typedef set<int> SETI;
 
typedef multiset<int> MSETI;
 
typedef long int li;
 
typedef unsigned long int uli;
 
typedef long long int ll;
 
typedef unsigned long long int  ull;
const ll N = 1e4;



ll fastexp (ll a, ll b, ll n) {
  ll res = 1;
  while (b) {
      if (b & 1) res = res*a%n;
      a = a*a%n;
      b >>= 1;
  }
  return res;
}
void fast(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
}
int diff(string a,string b){
    int dc=0;
    fore(i,a.length()){
        if(a[i]!=b[i])dc++;
    }
    return dc;
}

int n,k;
ll dp[50][50][3000];
int a[50];
ll solve(ll index,ll total,ll sum)
{
    if(index==n)
    {
        if(total!=0 && sum%total==0)
        {
            if(sum/total==k)  return 1;
            else return 0;
        }
        else   return 0;
    }
    ll ans = dp[index][total][sum];
    if(ans!=-1)   return ans;
    ans = 0;
    ans += solve(index+1,total+1,sum+a[index]);
    ans += solve(index+1,total,sum);
    return dp[index][total][sum] = ans;
}
int main() 
{
    fast();
    cin >> n >> k;
    fore(i,n)cin >> a[i];
    mem(dp,-1);
    ll ans = solve(0,0,0);
    cout<<ans;
    
}    