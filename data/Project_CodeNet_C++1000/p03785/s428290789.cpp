#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll N;
    cin >> N;
    ll C;
    cin >> C;
    ll K;
    cin >> K;
    vector<ll> T(N,0);
    for(ll i=0;i<N;i++)cin>>T[i];
    sort(T.begin(), T.end());
    //最終バスの人数、出発時刻
    ll people=1;
    ll bus=T[0];
    ll count=1;
    for(ll i=1;i<N;i++){
        //新しいバス不要
        if(T[i]<=bus+K&&people<C){
            people++;
        }
        else{
            bus=T[i];
            people=1;
            count++;
        }
    }
    print(count)


    return 0;
}