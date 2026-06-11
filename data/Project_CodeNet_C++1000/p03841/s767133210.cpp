#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;}
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<Pii> v(N);
    rep(i,N){
        int x; cin >> x;
        v[i]={--x,i+1};
    }
    sort(all(v));
    vector<int> ans,cnt(N,0);
    int now1=0,now2=0;
    bool round=false;
    rep(i,N*N){
        if (now1<N&&i==v[now1].first){
            int x=v[now1].second;
            if (cnt[x-1]!=x-1){
                cout << "No" << endl;
                return 0;
            }
            ans.push_back(x);
            ++cnt[x-1];
            ++now1;
        }
        else {
            if (!round&&v[now2].second==1){
                ++now2;
                if (now2==N) round=true,now2=0;
            }
            if (round&&v[now2].second==N){
                if (cnt[N-1]<N){
                    cout << "No" << endl;
                    return 0;
                }
                ++now2;
            }
            int x=v[now2].second;
            if (round&&cnt[x-1]<x){
                cout << "No" << endl;
                return 0;
            }
            ans.push_back(x);
            ++cnt[x-1];
            if (!round&&cnt[x-1]==x-1){
                ++now2;
                if (now2==N) round=true,now2=0;
            }
            if (round&&cnt[x-1]==N) ++now2;
        }
    }
    cout << "Yes" << endl;
    rep(i,N*N){
        cout << ans[i];
        if (i!=N*N-1) cout << ' ';
        else cout << endl;
    }
}