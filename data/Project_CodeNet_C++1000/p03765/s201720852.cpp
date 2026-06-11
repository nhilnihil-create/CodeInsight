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
#define gb(i,j) ((i>>j)&1)
#define name "a"
#define endl '\n'

using namespace std;

const int mod=1e9+7;

string S;
int s1[maxn],s2[maxn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> S;
    int n=0;
    for(char c:S){
        ++n;
        s1[n]=s1[n-1];
        if(c=='A')s1[n]+=1;
        else s1[n]+=2;
    }
    cin >> S;
    int m=0;
    for(char c:S){
        ++m;
        s2[m]=s2[m-1];
        if(c=='A')s2[m]+=1;
        else s2[m]+=2;
    }
    int q;
    cin >> q;
    while(q--){
        int x,y,u,v;
        cin >> x >> y >> u >> v;
        if((s1[y]-s1[x-1]-s2[v]+s2[u-1])%3==0)cout <<"YES\n";
        else cout << "NO\n";
    }
    return 0;
}
