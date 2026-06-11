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
bool comp(pair<ll, ll> a, pair<ll , ll> b) {
    // 基本はfirstで比較
    if(a.first != b.first){
         return a.first < b.first; // 昇順
        //return a.first > b.first; // 降順
    }

    // それ以外はsecondで比較
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        // どちらも同じ
        return true;
    }
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    ll k,l;
    string str;
    ll q;
    cin>>n;
    vector<pair<ll,ll>> v(n);
    rep(i,n){
        cin>>a>>b;
        v[i]=make_pair(b,a);
    }
    sort(all(v),comp);
    sum+=v[0].second;
    sum+=v[0].first;
    cout<<sum<<endl;
    return 0;
}
