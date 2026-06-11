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
    ll n,m,ans=0; cin>>n>>m;
    vector<ll> a(n,0),s(m,0);
    priority_queue<pair<ll,ll>> que;
    rep(i,n){
        cin>>a[i]; a[i]--;
    }
    rep(i,n-1){
        ll from=a[i],to=a[i+1];
        if(from>to) to+=m;
        ans+=to-from;
        if(to-from>1){
            que.push(mk(-(from+2),-1));
            que.push(mk(-(to+1),to-from-1));
        }
    }
    ll cur=0,cnt=0,idx=0,q;
    while(!(que.empty())){
        while(!(que.empty()) && que.top().first==-idx){
            tie(ignore,q)=que.top();
            que.pop();
            if(q==-1) cnt++;
            else{
                cur-=q; cnt--;
            }
        }
        cur+=cnt;
        s[(2*m-idx)%m]+=cur;
        idx++;
    }
    ll res=ans;
    rep(i,m) res=min(res,ans-s[i]);
    cout<<res<<endl;
}