#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6+10;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl
#define Cerr(x) cerr<<(x)<<endl
#define fi first
#define se second

ll n,cnt,a,b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k,H,W;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};
ll ans[505][505];

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>H>>W>>h>>w;
    rep(i,H)rep(j,W)ans[i][j]=1000;
    pos=1000*(h*w-1)*-1;
    pos--;
    ans[h-1][w-1]=pos;
    for(int i=h-1;i<H;i+=h){
        for(int j=w-1;j<W;j+=w){
            ans[i][j]=pos;
        }
    }
    rep(i,H)rep(j,W)sum+=ans[i][j];
    if(sum<=0)Cout("No");
    else{
        Cout("Yes");
        rep(i,H){
            rep(j,W){
                if(j==W-1)Cout(ans[i][j]);
                else cout<<ans[i][j]<<" ";
            }
        }
    }
    return 0;
}
