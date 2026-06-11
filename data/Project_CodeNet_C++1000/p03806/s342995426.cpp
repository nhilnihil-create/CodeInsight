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
    ll N,A,B;
    cin >>N>>A>>B;
    vector<ll>a(N),b(N),c(N);
    rep(i,N){
        cin>>a[i]>>b[i]>>c[i];
    }

    vector<vector<vector<ll>>>dp(N+1,vector<vector<ll>>(405,vector<ll>(405,INF)));
    dp[0][0][0]=0;
    rep(i,N){
        rep(j,403){
            rep(k,403){
                if(j-a[i]>=0 && k-b[i]>=0){
                    dp[i+1][j][k]=min({dp[i][j][k],dp[i][j-a[i]][k-b[i]]+c[i]});
                }else{
                    dp[i+1][j][k]=dp[i][j][k];
                }
            }
        }
    }
    /*rep(i,N){
        if(ans==INF){
        cout<<-1<<endl;
        }else{
            cout << ans << endl;
        }
    }*/
    ll ans=INF;
    rep2(i,N){
        if(A*i>402||B*i>402)break;
        chmin(ans,dp[N][A*i][B*i]);
    }
    if(ans==INF){
        cout<<-1<<endl;
    }else{
        cout << ans << endl;
    }
    


    return 0;
    

}