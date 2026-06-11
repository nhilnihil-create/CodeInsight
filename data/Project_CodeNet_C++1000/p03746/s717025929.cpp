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

ll n,cnt,a[ohara],b[ohara],c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};
vector<ll> g[ohara];
bool vi[ohara];
ll ans_cou;
deque<ll> ans;

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    rep(i,m){
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    ans.push_front(0LL);
    vi[0]=true;
    rep(i,Size(g[0])){
        if(!vi[g[0][i]]){
            if(cnt==0){
                ans.push_front(g[0][i]);
                vi[g[0][i]]=true;
            }
            else{
                ans.push_back(g[0][i]);
                vi[g[0][i]]=true;
            }
            cnt++;
            if(cnt>=2)break;
        }
    }
    ll now;
    while(1){
        //左端
        int ok=0;
        now=ans[0];
        rep(i,Size(g[now])){
            if(!vi[g[now][i]])ok=1;
        }
        if(ok){
            rep(i,Size(g[now])){
                if(!vi[g[now][i]]){
                    vi[g[now][i]]=true;
                    ans.push_front(g[now][i]);
                    break;
                }
            }
        }

        //
        int okk=0;
        now=ans[Size(ans)-1];
        rep(i,Size(g[now])){
            if(!vi[g[now][i]])okk=1;
        }
        if(!ok&&!okk)break;
        if(okk){
            rep(i,Size(g[now])){
                if(!vi[g[now][i]]){
                    vi[g[now][i]]=true;
                    ans.push_back(g[now][i]);
                    break;
                }
            }
        }
    }

    Cout(Size(ans));
    rep(i,Size(ans)){
        if(i==Size(ans)-1)Cout(ans[i]+1);
        else cout<<ans[i]+1<<" ";
    }
    return 0;
}
