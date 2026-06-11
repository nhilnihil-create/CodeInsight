#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};


int main() {
    ll N;
    string S1,S2;
    cin >>N>>S1>>S2;
    
    vector<bool>p;
    rep(i,N){
        if(S1[i]==S2[i]){
            p.pb(1);
        }else{
            p.pb(0);
            i++;
        }
    }
    ll ans;
    ll pr;
    if(p[0]==0){
        ans=6;
        pr=0;
    }else{
        ans=3;
        pr=1;
    }
    
    rep2(i,p.size()-1){
        if(p[i]==1){
            if(pr==1){
                ans=(ans*2)%mod;
            }
        }else{
            if(pr==1){
                ans=(ans*2)%mod;
            }else{
                ans=(ans*3)%mod;
            }
        }
        pr=p[i];
    }
    cout << ans << endl;


    return 0;
    

}