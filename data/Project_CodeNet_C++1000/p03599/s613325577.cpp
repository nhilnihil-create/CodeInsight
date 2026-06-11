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
    ll A,B,C,D,E,F;
    cin >>A>>B>>C>>D>>E>>F;
    A*=100;
    B*=100;
    ll ans1=A;
    ll ans2=0;
    ll now=0;
    rep(i,31){
        if(A*i>F) break;
        rep(j,31){
            ll w=A*i+B*j;
            if(w>F)break;
            rep(k,3001){
                if(w+k*C>F)break;
                if(k*C>E*w/100) break;
                rep(m,3001){
                    ll s=k*C+m*D;
                    if(w+s>F)break;
                    if(s>E*w/100) break;
                    if((ans1+ans2)*s>ans2*(w+s)){
                        ans1=w;
                        ans2=s;
                    }
                }
            }
        }
    }
    
    cout << ans1+ans2<<" "<<ans2 << endl;


    return 0;
    

}