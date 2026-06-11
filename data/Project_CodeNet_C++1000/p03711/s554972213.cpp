#include<bits/stdc++.h>
using namespace std;

/// Defining variable types.
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

/// Defining usable key words
#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

/// Defining constant variables.
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

/// Defining some useful lines.
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);


/// Code of debugger.
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}


int main()
{
    optimize();

    int a[]={1,3,5,7,8,10,12};
    int b[]={4,6,9,11};
    int cnt=0;
    int x,y;
    cin>>x>>y;

    if(x==2 || y==2)
    {
        cout<<"No"<<endl;
        return 0;
    }


    for(int i=0;i<7;i++)
    {
        if(a[i]==x)cnt++;
        if(a[i]==y)cnt++;
    }

    if(cnt==2)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    else if(cnt==1)
    {
        cout<<"No"<<endl;
        return 0;
    }

   else
    cout<<"Yes";

   /* for(int i=0;i<4;i++)
    {
        if(b[i]==x)cnt++;
        if(b[i]==y)cnt++;
    }

    if(cnt==2)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    else
    {
        cout<<"No"<<endl;
        return 0;
    }
*/












    return 0;
}
