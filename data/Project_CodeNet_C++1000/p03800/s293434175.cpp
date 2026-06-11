#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define F first
#define S second
#define pb push_back
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
char ulta(char ch)
{
    if(ch=='W')
        return 'S';
    if(ch=='S')
        return 'W';
    if(ch=='o')
        return 'x';
    if(ch=='x')
        return 'o';
}
string ans;
int F;
void make(char a,char b,int n,string str)
{
    int i;
    ans.clear();
    ans.pb(a);
    ans.pb(b);
    lp(i,1,n)
    {
        if(str[i]=='o')
        {
            if(ans[i]=='W')
                ans.pb(ulta(ans[i-1]));
            if(ans[i]=='S')
                ans.pb(ans[i-1]);
        }
        else
        {
            if(ans[i]=='S')
                ans.pb(ulta(ans[i-1]));
            if(ans[i]=='W')
                ans.pb(ans[i-1]);
        }
    }
    if(ans[0]!=ans[n])
    {
        F=0;
        return ;
    }
    F=1,i=0;
    if(str[i]=='o')
    {
        if(ans[i]=='W' && ans[1]==ans[n-1])
            F=0;
        if(ans[i]=='S' && ans[1]!=ans[n-1])
            F=0;
    }
    else
    {
        if(ans[i]=='S' && ans[1]==ans[n-1])
            F=0;
        if(ans[i]=='W' && ans[1]!=ans[n-1])
            F=0;
    }
    return ;
}
int main()
{
    int i,n;
    string str;
    in(n);
    cin >> str;
    n=str.size();
    make('S','S',n,str);
    if(F)
    {
        llout(ans.substr(0,n));
        return 0;
    }
    make('S','W',n,str);
    if(F)
    {
        llout(ans.substr(0,n));
        return 0;
    }
    make('W','S',n,str);
    if(F)
    {
        llout(ans.substr(0,n));
        return 0;
    }
    make('W','W',n,str);
    if(F)
    {
        llout(ans.substr(0,n));
        return 0;
    }
    out(-1);
    return 0;
}


