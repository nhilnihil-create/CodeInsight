#include <bits/stdc++.h>
typedef long long       ll;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define fore(i, b, e)      for(int i = b; i < e; i++)
#define forr(i, b, e)      for(int i = b; i < e; i++)
#define forg(i, b, e, m)  for(int i = b; i < e; i+=m)
#define F first
#define S second
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<int, int>  ii;
typedef pair<int, ii>  iii;
typedef vector<int>     vi;

typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
const double PI = acos(-1);
const double EPS = 1e-9;
#define tam 1234567
ll minn=1e13;
ll get(ll a,ll b)
{
    if (a==0|| b==0)
        return -minn;
    if (a<b)
        return get(b,a);
    minn=min(minn,a);
    minn=min(minn,b);
    return ll(a/b)*b*2+get(a-ll(a/b)*b,b);

}
int main()
{
    ll n,x;
    cin>>n>>x;
    
    
        cout<<get(n-x,x)+n<<endl;
    
}
// PLUS ULTRA!