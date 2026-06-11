/*input
3
2 3 1
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
typedef long long int ll;
#define ld long double
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
const ll maxn=20005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=4000000000000000LL;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,y)
ll mult(ll a,ll b){
    return ((a%MOD)*(b%MOD))%MOD;
}
ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=mult(res,a);
        a=mult(a,a);
        b>>=1;
    }
    return res;
}
int a[maxn],b[maxn],arr[maxn];
int main() {
    int n;
    cin>>n;
    REP(i,n){
        int x;
        cin>>x;
        arr[x]=i+1;
    }
    REP(i,n){
        int x=arr[i+1];
        a[x]=30000*x;
        b[x]=30000*(n-x)+arr[x];
    }
    REP(i,n) cout<<a[i+1]<<' ';
    cout<<'\n';
    REP(i,n) cout<<b[i+1]<<' ';
}