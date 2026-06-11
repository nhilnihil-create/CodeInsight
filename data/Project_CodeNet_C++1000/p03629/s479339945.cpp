#include <bits/stdc++.h>
using namespace std;typedef long long ll;typedef vector<ll> vl;typedef vector<vl> vvl;typedef pair<ll,ll> pl;typedef vector<pl> vp;const ll INF=1001001001;const ll LINF=1001001001001001001;const ll D4[]={0,1,0,-1,0};const ll D8[]={0,1,1,0,-1,-1,1,-1,0};template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
#define fore(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define rep(i,n) fore(i,0,(n)-1)
#define all(x) (x).begin(),(x).end()

void solve(std::string A){
    ll n=A.size();

    ll cnt=0;
    vl exs(26);
    vl idxs;
    idxs.push_back(n);
    ll k=1;
    vvl pos(26);
    rep(i,26)pos[i].push_back(n);
    for(ll i=n-1;i>=0;i--){
        ll x=A[i]-'a';
        if(!exs[x])cnt++;
        exs[x]++;
        if(cnt==26){
            k++;
            idxs.push_back(i);
            exs.assign(n,0);
            cnt=0;
        }
        pos[x].push_back(i);
    }
    rep(i,26)reverse(all(pos[i]));
    reverse(all(idxs));

    string ans;
    ll idx=-1;
    rep(i,k){
        rep(j,26){
            ll nxt=*upper_bound(all(pos[j]),idx);
            if(nxt>=idxs[i]){
                ans+=(char)('a'+j);
                idx=nxt;
                break;
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    std::string A;
    std::cin >> A;
    solve(A);
}
