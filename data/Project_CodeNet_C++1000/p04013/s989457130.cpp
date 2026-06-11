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
    ll N,A;
    cin >>N>>A;
    vector<ll>x(N);
    rep(i,N){
        cin>>x[i];
    }

    vector<vector<vector<ll>>>dp(N+1,vector<vector<ll>>(N+1,vector<ll>(3000)));
    
    rep(i,N+1){
        dp[i][0][0]=1;
    }
    rep(i,N){
        rep(j,N){
            rep(k,3000){
                if(k-x[i]>=0){
                    dp[i+1][j+1][k]=dp[i][j+1][k]+dp[i][j][k-x[i]];
                }else{
                    dp[i+1][j+1][k]=dp[i][j+1][k];
                }
            }
        }
    }
    ll ans=0;
    rep2(i,N){
        ans+=dp[N][i][A*i];
        //cout<<dp[N][i][A*i]<<endl;
    }
    cout << ans << endl;


    return 0;
    

}