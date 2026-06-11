#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt,ans,a[305][305],b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,flo[305][305];
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    rep(i,n)rep(j,n)cin>>a[i][j];
    rep(i,n+1){
        rep(j,n+1){
            if(i!=j)flo[i][j]=LINF;
        }
    }
    rep(i,n){
        rep(j,n){
            if(i>=j)continue;
            flo[i][j]=a[i][j];
            flo[j][i]=a[i][j];
        }
    }
    rep(i,n){
        rep(j,n){
            rep(k,n){
                flo[j][k]=min(flo[j][i]+flo[i][k],flo[j][k]);
            }
        }
    }
    rep(i,n){
        rep(j,n){
            if(i>=j)continue;
            if(flo[i][j]!=a[i][j]){
                Cout(-1);
                return 0;
            }
        }
    }
    rep(i,n){
        rep(j,n){
            if(i>=j)continue;
            ll fr,to;
            fr=i;to=j;
            b=0;
            rep(k,n){
                if(fr==k||to==k)continue;
                if(flo[fr][to]==flo[fr][k]+flo[k][to])b=1;
            }
            if(!b)ans+=a[i][j];
        }
    }
    Cout(ans);
    return 0;
}
