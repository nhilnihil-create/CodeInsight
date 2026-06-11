#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define ALL(obj) (obj).begin(), (obj).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dy[]={0, 0, 1, -1, 1, -1, -1, 1};
int dx[]={1, -1, 0, 0, 1, 1, -1, -1};


int main() {
    cout<<fixed<<setprecision(10);

    ll n; cin>>n;
    vint a(n); rep(i,n) cin>>a[i];

    sort(ALL(a), greater<ll>());
    map<ll,ll> cnt;
    for(auto e:a) cnt[e]++;
    ll maxval = a.front();
    ll minval = a.back();


    // if(cnt[maxval] == 1){puts("Impossible"); return 0;}
    if((maxval+1)/2 != minval){puts("Impossible"); return 0;}


    if(maxval%2 == 0){
        if(cnt[minval] != 1){puts("Impossible"); return 0;}
        for(ll i = minval+1; i<=maxval; i++){
            if(cnt[i]<2){puts("Impossible"); return 0;}
        }
    }else{
        if(cnt[minval] != 2){puts("Impossible"); return 0;}
        for(ll i = minval+1; i<=maxval; i++){
            if(cnt[i]<2){puts("Impossible"); return 0;}
        }
    }

    puts("Possible");




    return 0;

}