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

int main() {
    string a; cin>>a;
    ll n=a.size();
    ll ans=n*(n-1)/2;
    vector<ll> cnt(26,0);
   
    for(auto ch : a) cnt[ch-'a']++;
    rep(i,26) ans-=cnt[i]*(cnt[i]-1)/2;
    cout<<ans+1<<endl;
}