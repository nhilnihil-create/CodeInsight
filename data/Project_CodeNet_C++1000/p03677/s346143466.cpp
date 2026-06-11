#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++)
#define ltype int
#define rep(i,j,k) for(ltype(i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(ltype(i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(ltype(i)=(j);(i)>=(k);(i)--)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,mod=1000000007;
const double pi=3.1415926535897932,eps=1e-6;
void chmax(int &x,int y){if(x < y) x = y;}
void chmin(int &x,int y){if(x > y) x = y;}
int n,a[100005],m;ll dd[100005],d[100005],x[100005];
ll offset;
void add(int l,int r,int x){
    if(l > r) return;
    dd[l] += x;
    dd[r+1] -= x;
}
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",a+i);
    rap(i,1,n) {
        if(a[i] < a[i+1]){
            offset += a[i+1] - a[i];
            //rep(j,a[i]+1,a[i+1]) d[j]--;
            //d[a[i+1]+1] += a[i+1] - a[i] - 1;
            add(a[i]+2, a[i+1], -1);
            add(a[i+1]+1, a[i+1]+1, a[i+1] - a[i] - 1);
        }
        else {
            offset += m - a[i] + a[i+1];
            //rep(j,a[i]+2,m) d[j]--;
            //d[1] -= (m - a[i] - 1);
            //rep(j,1,a[i+1]) d[j]--;
            //d[a[i+1]+1] += m - a[i] + a[i+1] + 1;
            add(a[i]+2, m, -1);
            add(1, 1, -(m - a[i] - 1));
            add(1, a[i+1], -1);
            add(a[i+1]+1, a[i+1]+1, m - a[i] + a[i+1] - 1);
        }
    }
    rep(i,1,m) d[i] = d[i-1] + dd[i];
    rep(i,1,m) x[i] = x[i-1] + d[i];
    //rep(i,1,m) printf("%d ",x[i] + offset);
    ll u = (ll)4e18;rep(i,1,m) u = min(u, x[i] + offset);
    printf("%lld\n",u);
    return 0;
}