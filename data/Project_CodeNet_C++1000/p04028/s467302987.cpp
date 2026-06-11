//#pragma GCC optimize(2)


#include<bits/stdc++.h>
using namespace std;
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/rope>*/
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
//void err(istream_iterator<string> it){cerr<<endl;}
//template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args){cerr << *it << " = " << a << " , ";err(++it, args...);}
//#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define mem(a,b) memset((a),b,sizeof((a)))
#define fpre(x) cout<<fixed<<setprecision(x)
#define clr(v) (v).clear()
#define pii pair<int,int>
#define pdd pair<double,double>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define eb emplace_back
#define pb emplace_back
#define ll long long
#define ld long double
#define ull unsigned long long
#define uint unsigned int
#define ushort unsigned short
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lowbit(i) (i&(-i))
#define lson rt<<1
#define rson lson|1
#define fi first
#define se second
const double eps=1e-7;
const double pi=acos(-1);
inline int dcmp(double x)
{
    if(x<-eps)
        return -1;
    if(x>eps)
        return 1;
    return 0;
}
//-----------------------------------------------head


const ll mod=1e9+7;
char s[5050];
ll dp[5050][5050];
int main()
{
    int n,c;
    while(~scanf("%d%s",&n,s))
    {
        int l=strlen(s);
        mem(dp,0);
        dp[0][0]=1;
        for(int i=0;i<=n;++i)
        {
            (dp[i+1][0]+=dp[i][0])%=mod;
            for(int j=1;j<=n;++j)
                (dp[i+1][j-1]+=dp[i][j]*2)%=mod;
            for(int j=0;j<=n;++j)
                (dp[i+1][j+1]+=dp[i][j])%=mod;
        }
        printf("%lld\n",dp[n][l]);
    }
}

/*
























*/







