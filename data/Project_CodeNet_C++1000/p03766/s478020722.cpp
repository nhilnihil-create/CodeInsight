#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b;++i)
#define fdto(i,a,b) for(int i=a; i>=b;--i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define maxn 1000009
#define gb(i,j) ((i>>j)&1)
#define name "a"
#define endl '\n'

using namespace std;

ll f[maxn],s[maxn];
int mod=1e9+7,n;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    f[0]=1;
    s[0]=1;
    if(n==1){cout << 1; return 0;}
    for(int i=1; i<=n; ++i){
        f[i]=f[i-1];
        if(i>2)f[i]=(f[i]+s[i-3])%mod;
        s[i]=(f[i]+s[i-1])%mod;
    }
    ll res=(f[n]+f[n-1]*(n-1))%mod;
    fto(i,0,n-2){
        res=(res+f[i]*(i+1)%mod*n)%mod;
        res=(res+f[i]*(n-i-2)%mod*(n-1))%mod;
    }
    cout << res;
    return 0;
}
