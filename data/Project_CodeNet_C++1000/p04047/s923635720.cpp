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
int dp[300][300];
int arr[300];
int n;
int f(int pos,int ant)
{
    if (pos==2*n)
    {
        return 0;
    }
    if (dp[pos][ant]!=-1)
    {
        return dp[pos][ant];
    }
    int tot=0;
    if (pos+1<=2*n)
    tot=f(pos+2,ant)+arr[pos]; 
    if (ant==0)
    tot=max(tot,f(pos+1,pos));
    else
    tot=max(tot,f(pos+1,0)+arr[ant]);
    return dp[pos][ant]=tot;
}
int main()
{
    memset(dp,-1,sizeof dp);
    
    cin>>n;
    forr(i,1,2*n+1)
    {
        cin>>arr[i];
    }    
    sort(arr+1,arr+2*n+1);
    
    cout<<f(1,0)<<endl;
}
// PLUS ULTRA!