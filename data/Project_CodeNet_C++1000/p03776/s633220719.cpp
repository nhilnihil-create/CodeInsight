#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
typedef vector<int>vi;
typedef pair<int,int>pi;
typedef vector<pi>vpi;
typedef vector<vi>vvi;
#define double long double
#define pow powl
#define sqrt sqrtl
#define cbrt cbrtl
#define floor floorl
#define ceil ceill
#define pb push_back
#define ep emplace_back
#define PB pop_back
#define pf push_front
#define ef emplace_front
#define PF pop_front
#define mp make_pair
#define ub(a,b) upper_bound(all(a),b)-a.begin()
#define lb(a,b) lower_bound(all(a),b)-a.begin()
#define bs(a,b) binary_search(all(a),b)
#define mem(a,b) memset(a,b,sizeof(a))
#define in(a,n) FOR(i,0,n-1) cin>>a[i]
#define in1(a,n) FOR(i,1,n) cin>>a[i]
#define ff first
#define ss second
#define out(a,n) FOR(i,0,n-1) cout<<a[i]<<" ";cout<<endl;
#define out1(a,n) FOR(i,1,n) cout<<a[i]<<" ";cout<<endl;
#define clr(a) a.clear()
#define pow2(a) (1LL<<a)
#define all(a) a.begin(),a.end()
#define all1(a) a.begin()+1,a.end()
#define rall(a) a.rbegin(),a.rend()
#define rall1(a) a.rbegin(),a.rend()
#define sz(a) ((int)a.size())
#define FOR(i,a,b) for(auto i=a;i<=b;i++)
#define NFOR(i,a,b) for(auto i=a;i>=b;i--)
const int mod=1e9+7;

inline int add(int a,int b){return (a%mod + b%mod)%mod;}
inline int sub(int a ,int b){return (a%mod - b%mod + mod)%mod;}
inline int mul(int a,int b){return (a%mod * b%mod)%mod;}
inline int power(int a,int b,int MOD){int res=1;while(b){if(b&1){res*=a;res%=MOD;}a=a*a;a%=MOD;b>>=1;}return res;}

#define trace(x) cout<<#x<<" :: "<<x<<endl;
#define trace2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define trace3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define trace4(x,y,z,w) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#w<<" :: "<<w<<endl;
clock_t time_p = clock();
void time()
{
  time_p = clock() - time_p;
  cerr << "Time elapsed : " << (double)(time_p)/CLOCKS_PER_SEC <<endl;
}
int C(int n, int r)  //Calculating nCr value without overflow
{
    if(r > n - r) r = n - r; 
    int ans = 1;
    for(int i = 1; i <= r; i++) {
        ans *= (n - r + i);
        ans /= i;
    }
    return ans;
}
signed main()
{

   // freopen("input.txt","r",stdin);
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int n,a,b;
   cin>>n>>a>>b;
   vector<int>v;
   int res=0; 
   map<int,int>f;      //Storing frequencies of the elements
   for(int i=0;i<n;i++)
   {
        int x;
        cin>>x;
        v.emplace_back(x);
        f[x]++;
   }
   sort(v.begin(),v.end());  
   int sum=0;
   int numbers=0;
   reverse(v.begin(),v.end());  //Reverse sorting for finding maximum possible average of the elements
   for(int i=0;i<a;i++)
    sum+=v[i];
   vector<pair<double,int> >averages;  //Storing averages along with indices
   averages.emplace_back(make_pair(((double)sum) / a,a-1)); 
   for(int i=a;i<b;i++)
   {
       sum+=v[i];
       averages.emplace_back(make_pair(((double)sum)/(i + 1),i));
   } 
   sort(averages.begin(),averages.end());  //For finding maximum possible averages
   double maximum=averages[b-a].first;
   vector<int>indices;   //Storing indices with maximum possible sum
   for(int i=0;i<=b-a;i++)
   {
         if(averages[i].first==maximum)
          indices.emplace_back(averages[i].second);
   }
   sort(indices.begin(),indices.end());
   for(auto &x:indices)
   {
        int ways=1;
        map<int,int>z;
        for(int i=0;i<=x;i++)
          z[v[i]]++;     //Finding frequency of all elements required in maximum subset
        for(auto &x:z)
        {
           ways*=C(f[x.first],x.second);  //Finding number of subsets
        }
        res+=ways;
   }
   cout<<setprecision(15)<<fixed<<maximum<<endl<<res<<endl;
   time();
   return 0;
}
