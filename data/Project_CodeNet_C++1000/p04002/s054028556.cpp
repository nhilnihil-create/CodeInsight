#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
#define Complex complex<double>
int dx[3]={1,0,-1};
int dy[3]={1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

int main() {
    int h,w,n;
    cin >> h >> w >> n;
    map<pii,int> ma;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        for(auto x:dx){
            for(auto y:dy){
                ma[mp(a+x,b+y)]++;
            }
        }
    }
    ll sum[10]={};
    sum[0]=(ll)(h-2)*(ll)(w-2);
    for(auto x:ma){
        if(0<x.F.F && x.F.F<h-1 && 0<x.F.S && x.F.S<w-1){        
            sum[x.S]++;
            sum[0]--;
        }
    }
    rep(i,10){
        cout << sum[i] << endl;
    }

    
}