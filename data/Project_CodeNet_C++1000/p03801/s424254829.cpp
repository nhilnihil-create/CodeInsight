#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

//最大のやつらを集めて，その中の一番番号若いやつを使って次に大きいやつらにそろえる．
//バグ取り小宮
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    vector<ll> a(n);
    priority_queue<pair<ll,int>> q;
    rep(i,n){
        cin>>a[i];
        q.push(make_pair(a[i],-i));
    }
    vector<ll> cnt(n);
    int mugen=0,idx=INF;ll num=q.top().first;
    while(!q.empty()){
        while(!q.empty()&&(q.top()).first==num){
            idx=min(idx,-q.top().second);
            q.pop();mugen++;
        }
        ll nextnum=q.empty()?0ll:q.top().first;
        cnt[idx]+=(num-nextnum)*mugen;
        num=nextnum;
    }
    for(auto x:cnt)cout<<x<<endl;
    return 0;
}
