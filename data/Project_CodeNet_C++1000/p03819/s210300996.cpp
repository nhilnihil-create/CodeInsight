#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> ii;
#define F first
#define S second
#define sqr(x) (x)*(x)
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,x,y) for(int i=x;i<(y);++i)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
/* start */

const int N = 1e5+9;

int b[N];

void update(int l,int r){
    for(;l<N;l += l&-l){
        b[l]++;
    }
    r++;
    for(;r<N;r += r&-r){
        b[r]--;
    }
}

int soma(int i){
    int ans=0;
    for(;i>0;i -= i&-i) ans+=b[i];
    return ans;
}

signed main(){
    IOS;
    int n,m; cin >> n >> m;
    vector<pair<int,ii> > v;
    rep(i,0,n){
        int x,y; cin >> x >> y;
        v.pb(mp(y-x+1,ii(x,y)));
    }
    sort(all(v));
    int cur = 0;
    rep(i,1,m+1){
        if(cur<sz(v)){
            while(v[cur].F < i){
                int l = v[cur].S.F, r = v[cur].S.S;
                update(l,r);
                cur++;
                if(cur==sz(v)) break;
            }
        }
        int k = 0;
        for(int j = i;j<=m;j+=i){
            k+=soma(j);
        }
        cout << k + n - cur << "\n";
    }
}