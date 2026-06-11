#include <bits/stdc++.h>
using namespace std;
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(0),cin.tie(0);
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define mt make_tuple
#define all(a) a.begin(),a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1<<(i-1)))
#define gg exit(0);

int pf[2][100010];

main(){
    #define task "TrBBnsformBBtion"
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    fasty;

    forinc(i,0,1){
        string s; cin>>s;
        forinc(j,1,s.size()){
            pf[i][j]=(pf[i][j-1]+(s[j-1]=='A'?1:2))%3;
        }
    }
    int q; cin>>q; while(q--){
        int x,y,u,v; cin>>x>>y>>u>>v;
        cout<<((pf[0][y]-pf[0][x-1]+3)%3==(pf[1][v]-pf[1][u-1]+3)%3 ? "YES\n" : "NO\n");
    }
}

