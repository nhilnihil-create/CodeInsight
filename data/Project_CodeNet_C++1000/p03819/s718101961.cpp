#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b;++i)
#define fdto(i,a,b) for(int i=a; i>=b;--i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define ll long long
#define maxn 300009
#define maxm 100009
#define gb(i,j) ((i>>j)&1)
#define name "a"
#define endl '\n'

using namespace std;
int l[maxn],r[maxn];
int t[maxm],m,n;
void add(int x, int y){
    for(;x<=m; x+=x&-x)t[x]+=y;
}

int get(int x){
    int res=0;
    for(;x;x-=x&-x)res+=t[x];
    return res;
}
pii c[maxn];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    #endif // ONLINE_JUDGE
    cin >> n >> m;
    fto(i,1,n){
        cin >> l[i] >> r[i];
        c[i]=mp(r[i]-l[i]+1,i);
    }
    sort(c+1,c+n+1);
    int j=1;
    for(int i=1; i<=m; ++i){
        while(c[j].fi <i && j<=n){
            int t=c[j].se;
            add(l[t],1);
            add(r[t]+1,-1);
            ++j;
        }
        int res=n-j+1;
        for(int t=0; t<=m; t+=i)res+=get(t);
        cout << res<<endl;
    }
    return 0;
}
