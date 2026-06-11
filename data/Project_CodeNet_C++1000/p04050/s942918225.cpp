# include <bits/stdc++.h>
# define il inline
# define fi first
# define se second
# define pb push_back
# define mem(x,v) memset(x,v,sizeof x)
# define rep(i,x,y) for(int i=x;i<=y;++i)
# define re(i,x,y) for (int i=x;i<y;++i)
using namespace std;
typedef long long ll;
il ll read(){
    ll x=0; char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return x;
}
const int maxm = 100+10;
int n,m;
int a[maxm];
vector<int> b;
int main(){
    n=read(); m=read();
    rep(i,1,m) a[i]=read();
    if (m == 1){
        b.pb(1); b.pb(n-1);
    }
    else{
        int cnt = 0;
        rep(i,1,m) cnt += a[i] % 2;
        if (cnt > 2){
            puts("Impossible"); return 0;
        }
        rep(i,2,m-1)
            if (a[i]%2==1){
                if (a[1]%2==0)swap(a[1],a[i]);
                else swap(a[m],a[i]);
            }
        b.pb(a[m]+1);
        for (int i=m-1;i>1;--i) b.pb(a[i]);
        b.pb(a[1]-1);
    }
    rep(i,1,m) printf("%d ",a[i]); printf("\n");
    int bs=b.size();
    if (b[bs-1] == 0)--bs;
    printf("%d\n",bs);
    for (int i=bs-1;i>=0;--i) printf("%d ",b[i]); printf("\n");
    return 0;
}