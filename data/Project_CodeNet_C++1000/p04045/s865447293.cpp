
///-----Bismillahir Rahmanir Rahim-----///

#include<bits/stdc++.h>
using namespace std;

///---FAST I/O---///
#define Boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

///---DATA TYPE---///
typedef long long ll;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;

///---LOOP---///
#define rep0(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)

///---I/O---///
#define sf scanf
#define pf printf

///---OTHERS---///
#define pb push_back
#define all(c)		c.begin(),c.end()
#define MK make_pair
#define F first
#define S second
#define endl '\n'


///---INITIALIZATION---//
#define mem(a,b) memset(a, b, sizeof(a) )

///---CALCULATE---///
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

///---BIT OPERATION---///
inline bool checkBit(ll n, int i)
{
    return n&(1LL<<i);
}
inline ll setBit(ll n, int i)
{
    return n|(1LL<<i);;
}
inline ll resetBit(ll n, int i)
{
    return n&(~(1LL<<i));
}

///------String/Char Related Functions-----///
string makeintString(int x)
{
    stringstream ss;
    ss << x;
    string str = ss.str();
    ///cout<<str<<endl;
    return str;
}
string makellString(ll x)
{
    stringstream ss;
    ss << x;
    string str = ss.str();
    ///cout<<str<<endl;
    return str;
}
char cpp(char c)
{
    return static_cast<char>(c + 1);
}

///------------Sorting STL----------///
struct func
{
    //this is a sample overloading function for sorting stl
    bool operator()(pii const &a, pii const &b)
    {
        if(a.F==b.F)
            return (a.S<b.S);
        return (a.F<b.F);
    }
};

///---CONSTANT---///
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

int dis[10];
int main()
{
    Boost();

    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        int n,k,x,ans;
        cin>>n>>k;
        for(int i=0; i<k; i++)
        {
            cin>>x;
            dis[x]=1;
        }
        for(int i=n; i<=100000; i++)
        {
            int tmp=i,flag=0;
            while(tmp>0)
            {
                int d=tmp%10;
                if(dis[d]==1)
                {
                    flag=1;
                    break;
                }
                tmp/=10;
            }
            //cout<<flag<<" "<<i<<endl;
            if(flag==0)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
