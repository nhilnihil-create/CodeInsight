#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b;++i)
#define fdto(i,a,b) for(int i=a; i>=b;--i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define ll long long
#define maxn 100009
#define gb(i,j) ((i>>j)&1)
#define name "a"
#define endl '\n'
#define int ll

using namespace std;

const int mod=1e9+7;

pii a[maxn];
int t[maxn],s[maxn],n;

void add(int x){
    for(;x; x-=x&-x)++t[x];
}

int get(int x){
    int res=0;
    for(;x<=n; x+=x&-x)res+=t[x];
    return res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fto(i,1,n){
        cin >> a[i].fi;
        a[i].se=i;
    }
    sort(a+1,a+n+1,greater<pii>());
    int top=n;
    for(int i=1; i<=n;){
        int x=a[i].fi;
        while(a[i].fi==x && i<=n){
            top=min(top,a[i].se);
            add(a[i].se);
            ++i;
        }
        s[top]+=get(top)*(a[i-1].fi-a[i].fi);
    }
    fto(i,1,n) cout << s[i]<<endl;

    return 0;
}
