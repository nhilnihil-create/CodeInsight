#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}
const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
//template end

int dp[22][100010];

int main(){
    int n; scanf("%d",&n);
    vector<int> a(n);
    rep(i,0,n)scanf("%d",&a[i]);
    int l; scanf("%d",&l);
    rep(i,0,n)dp[0][i]=lower_bound(ALL(a),a[i]+l+1)-a.begin()-1;
    rep(i,0,20)rep(j,0,n)dp[i+1][j]=dp[i][dp[i][j]];
    int q,ans; scanf("%d",&q);
    rep(rot,0,q){
        int l,r; scanf("%d%d",&l,&r); l--; r--;
        if(l>r)swap(l,r);
        ans=1; rrep(i,19,-1)if(dp[i][l]<r)l=dp[i][l],ans+=1<<i; 
        printf("%d\n",ans);
    }
    return 0;
}