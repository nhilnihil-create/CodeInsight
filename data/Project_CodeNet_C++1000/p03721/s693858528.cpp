// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
// -fsanitize=undefinedでオーバーフロー検出
#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
typedef pair<ll,ll> P;


bool comp(pair<ll, ll> a, pair<ll , ll> b) {
    // 基本はfirstで比較
    if(a.first != b.first){
         return a.first < b.first; // 昇順
        //return a.first > b.first; // 降順
    }
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    //double mini=INF;
    ll maxi=0,f=0,sum=0,mini=INF;
    string str,str1,str2;
    ll i;
    double h;
    ll n,x,m;
    ll a,b,d,c,k;
    //multiset<pair<string,ll>> s;
    cin>>n>>k;
    vector<P> p(n);
    rep(i,n){
        cin>>a>>b;
        p[i]=P(a,b);
    }
    sort(all(p),comp);
    rep(i,n){
        sum+=p[i].second;
        if(sum>=k){
            cout<<p[i].first<<endl;
            return 0;
        }
    }
    return 0;
}
