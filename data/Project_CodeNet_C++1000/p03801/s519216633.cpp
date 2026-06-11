#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define F first
#define S second
#define pb emplace_back
#define mt make_tuple
#define mp make_pair
#define gcd __gcd
#define PI 3.141592653589
// Input
#define in(a) scanf("%d",&a)
#define in2(a,b) scanf("%d%d",&a,&b)
#define in3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define llin(a) cin >> a
#define inl(a) scanf("%lld",&a)
#define read(v,i,n) for(i=0;i<n;i++)in(v[i])
#define twod(mat,i,j,n,m) rep(i,n){rep(j,m)in(mat[i][j]);}
#define sc(ch) scanf("%c",&ch)
#define sstr(str) scanf("%s",str)
// Output
#define pr(a) printf("%d ",a)
#define pr2(a,b) printf("%d %d\n",a,b)
#define pr3(a,b,c) printf("%d %d %d\n",a,b,c)
#define out(a) printf("%d\n",a)
#define outl(a) printf("%lld\n",a)
#define llpr(a) cout << a << " "
#define llout(a) cout << a << "\n"
#define yes printf("YES\n")
#define no printf("NO\n")
#define lin printf("\n")
// Iterator
#define lp(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define all(vec) vec.begin(),vec.end()
#define lower(v,k) lower_bound(v.begin(),v.end(),k)-v.begin()
#define upper(v,k) upper_bound(v.begin(),v.end(),k)-v.begin()
#define tf(mytuple) get<0>(mytuple)
#define ts(mytuple) get<1>(mytuple)
#define tt(mytuple) get<2>(mytuple)
// Debug
#define dbg(v,i,n) for(i=0;i<n;i++)pr(v[i]); lin
#define what(x) cerr << #x << " : " << x << "\n"
#define ck printf("continue\n")
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}
// Data Type
#define ll long long int
#define ii pair<int,int>
#define pli pair<ll,int>
#define triple tuple<int,int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vector<int> >
#define viii vector<pair<pair<int,int>,int> >
#define vvii vector<vector<pair<int,int> > >
#define M 1000000007
#define N 100005  //check the limits, man
const ll INF = 1e18;
int main()
{
    int i,j,n,a;
    in(n);
    vi ar(n);
    vi v(n);
    read(ar,i,n);
    vii asc;
    v[0]=ar[0];
    asc.pb(v[0],0);
    vector<ll> ans(n,0),bit(n+1,0);
    ii temp;
    lp(i,1,n)
    {
        v[i]=max(ar[i],v[i-1]);
        if(v[i]>v[i-1])
            asc.pb(v[i],i);
        else
        {
            temp=make_pair(ar[i],n);
            j=upper(asc,temp);
            bit[0]++,bit[j]--;
            if(j>0)
                ans[asc[j].S]+=(ar[i]-asc[j-1].F);
            else
                ans[asc[j].S]+=(ar[i]);
        }
    }
    int m=asc.size();
    lp(i,1,m)
        bit[i]+=bit[i-1];
    rep(i,m)
        bit[i]+=(m-i);
    lp(i,1,m)
        bit[i]*=(asc[i].F-asc[i-1].F);
    bit[0]*=asc[0].F;
    rep(i,m)
        a=asc[i].S,ans[a]+=bit[i];
    rep(i,n)
        llout(ans[i]);
}



