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
    ll n; cin>>n;
    map<ll,ll> m;
    vector<ll> q;
    rep(i,n){
        ll a; cin>>a;
        if(!(m.count(a))) m[a]=0;
        m[a]++;
        if(m[a]==2){
            q.push_back(a);
            m.erase(a);
        }
    }
    if((int)q.size()<2) cout<<0<<endl;
    else{
        sort(al(q)); reverse(al(q));
        cout<<q[0]*q[1]<<endl;
    }
}
