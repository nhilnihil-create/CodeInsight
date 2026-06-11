#include<bits/stdc++.h>
#define FF ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(value, size) cout << bitset<size>(value) << '\n'
#define PI acos(-1.0)   //3.1416(180 degree to radian)
#define PIby2 asin(1)     //(3.1416/2) for angle(90 degree to radian)
#define eps 1e-67
#define pf printf
#define sf scanf
#define sz size()
#define rr read
#define ww write
#define clr(arr) memset((arr),0,(sizeof(arr)))
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define repb(i,a,b) for(long long int i=a;i>=b;i--)
#define repa(i,a,b,c) for(long long int i=a;i<b;i=i+c)
#define reps(i,a,b,c) for(long long int i=a;i>b;i=i-c)
#define asort(a) sort(a.begin(),a.end())
#define asort2(a,comp) sort(a.begin(),a.end(),comp)
#define arev(a) reverse(a.begin(),a.end())
#define all(v) (v).begin(),(v).end()
#define all2(v,a,b) (v).begin()+a,(v).end()-b
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define pbb pop_back
#define mp make_pair
#define mt make_tuple
#define BS(v,x) binary_search(v.begin(),v.end(),x) //return true /false
#define LB(v,x) lower_bound(v.begin(),v.end(),x) //found and that value and not found than greater value pos
#define UB(v,x) upper_bound(v.begin(),v.end(),x) //found and greater value pos && not found also greater pos
#define convertlower(c) towlower(c)
#define root(x) sqrt(x)
#define power(a,n) pow(a,n)
#define tu(c) towupper(c)
#define sq(a) ((a)*(a))
#define cube(a) ((a)*(a)*(a))
#define mx 1000
#define MX 100000
#define mod 1000000007
#define INF 2000000000
#define N 10000000
#define Ceil(n) (long long int)ceil(n)
#define Floor(n) (long long int)floor(n)
#define deb(x) std::cout << #x << " = " << x << std::endl;
#define out(ans) cout<<ans<<endl
#define outs(ans) cout<<ans<<" "<<endl
using namespace std;

typedef string str;
typedef long long int ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef char ch;
typedef map<ll,ll> mpl;
int main()
{
    ll n,t,ans=0;
    cin>>n>>t;
    vll v(n+2),sum(n+1);
    rep(i,1,n+1)
    {
        cin>>v[i];
    }
    v[n+1]=INF;
    rep(i,1,n+1)
    {
        sum[i]=min(t,v[i+1]-v[i]);
        ans+=sum[i];
    }
    cout<<ans<<endl;
    return 0;
}
