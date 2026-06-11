#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const int mod=1000000007,INF=1001001001;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

#define int ll

int h,w,n,a,b;
int cnt[11];
vpint vec,at;

bool ex(int x,int y){
    int pos=lower_bound(vec.begin(),vec.end(),pint(x,y))-vec.begin();
    return pos<vec.size() && vec[pos]==pint(x,y);
}

signed main(){
    cin>>h>>w>>n;
    rep(i,0,n){
        cin>>a>>b;a--,b--;
        repe(j,a-2,a){
            repe(k,b-2,b){
                if(j>=0&&k>=0&&j+2<h&&k+2<w){
                    at.pb(pint(j,k));
                }
            }
        }
        vec.pb(pint(a,b));
    }
    sort(at.begin(),at.end());
    at.erase(unique(at.begin(),at.end()),at.end());
    sort(vec.begin(),vec.end());
    cnt[0]=(h-2)*(w-2)-at.size();
    rep(i,0,at.size()){
        int x=at[i].fi,y=at[i].se;
        int nm=0;
        repe(j,x,x+2)repe(k,y,y+2){
            nm+=ex(j,k);
        }
        cnt[nm]++;
    }
    rep(i,0,10)cout<<cnt[i]<<endl;
    return 0;
}