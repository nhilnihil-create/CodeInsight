#include<bits/stdc++.h>
#define PI acos(-1.0)
#define eps 1e-67
#define pf printf
#define sf scanf
#define sd(n) scanf("%d",&n)
#define sd2(n1,n2) scanf("%d %d",&n1,&n2)
#define slf(n) scanf("%lf",&n)
#define slf2(n1,n2) scanf("%lf %lf",&n1,&n2)
#define sLf(n1) scanf("%Lf",&n1)
#define sLf2(n1,n2) scanf("%Lf %Lf",&n1,&n2)
#define sl(n) scanf("%lld",&n)
#define sl2(n1,n2) scanf("%lld %lld",&n1,&n2)
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define repb(i,a,b) for(long long int i=a;i>=b;i--)
#define repa(i,a,b,c) for(long long int i=a;i<b;i=i+c)
#define reps(i,a,b,c) for(long long int i=a;i>b;i=i-c)
#define asort(a) sort(a.begin(),a.end())
#define asortb(a,comp) sort(a.begin(),a.end(),comp)
#define arev(a) reverse(a.begin(),a.end())
#define all(v) (v).begin(),(v).end()
#define allc(v,comp) (v).begin(),(v).end(),comp
#define allrc(v,a,b,comp) (v).begin()+a,(v).end()-b,comp
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define pbb pop_back
#define mp make_pair
#define mt make_tuple
#define bs(v,x) binary_search(v.begin(),v.end(),x)
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
#define tl(c) towlower(c)
#define root(x) sqrt(x)
#define power(a,n) pow(a,n)
#define tu(c) towupper(c)
#define sq(a) ((a)*(a))
#define cube(a) ((a)*(a)*(a))
#define mx 1000
#define MX 100000
#define mod 1000000007
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
typedef map<ll,ll> mp;
void Solve()
{
   int i,j,k,x1,y1,x2,y2,dify,difx;
   cin>>x1>>y1>>x2>>y2;
   string s1,s2,s3,s4,temp1,temp2,temp3,temp4,ans;
   dify=y2-y1;
   difx=x2-x1;
   rep(i,0,dify)
   {
       char c='U';
       temp1.pb(c);

   }
   rep(i,0,difx)
   {
       char d='R';
       temp2.pb(d);
   }
   s1=temp1+temp2;
   rep(i,0,dify)
   {
       char e='D';
       temp3.pb(e);
   }
      rep(i,0,difx)
   {
       char f='L';
       temp4.pb(f);
   }
   s2=temp3+temp4;
   s3='L'+temp1+'U'+temp2+'R'+'D';
   s4='R'+temp3+'D'+temp4+'L'+'U';
   ans=s1+s2+s3+s4;
   cout<<ans<<endl;

}

int main()
{
    Solve();
    return 0;
}