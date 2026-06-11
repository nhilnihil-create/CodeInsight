#include<bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define lint long long
#define ll long long
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define vl vector<long long>
#define pii pair<long long,long long>
#define all(x) (x).begin(),(x).end()
#define rep(x) for(int i = 0;i < (x);i++)
#define repj(x) for(int j = 0;j < (x);j++)
#define REP(i,x) for(int (i) = 0;(i) < (x);(i)++)
#define rrep(x) for(int i = (x);i >= 0;i--)
#define mod 1000000007
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define F first
#define S second
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a;a=1ll*a*a;}while(b>>=1);return ans;}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
long long INF = 1e9;

ll n,a,b;
ll h[100010];
bool solve(long long t){
    long long cnt = 0;
    for(int i = 0;i < n;i++){
        if(h[i] <= t*b) continue;
        else cnt += (h[i] - t*b - 1)/(a-b) + 1;
    }
    return (cnt <= t);
}
int main(void){
    cin>>n>>a>>b;
    rep(n) cin>>h[i];
    /////////////////

    ll lb = 0,ub = (ll)1e9;
    for(int i = 0;i < 1000;i++){
        ll m = (lb+ub)/2;
        if(solve(m)){
            ub = m;
        }else{
            lb = m + 1;
        }
        //debug(m);
        if(ub==lb)break;
    }
    cout << ub << endl;
    return 0;
}