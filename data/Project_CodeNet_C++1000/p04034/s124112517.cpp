//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,m; cin>>n>>m;
    vector<int> cnt(n,1);
    set<int> s; s.insert(0);
    rep(i,m){
        int x,y; cin>>x>>y;
        x--; y--;
        cnt[x]--; cnt[y]++;
        if(s.count(x)) s.insert(y);
        if(cnt[x]==0) s.erase(x);
    }
    int ans=0;
    rep(i,n){
        if(s.count(i) && cnt[i]>0) ans++;
    }
    cout<<ans<<endl;
}