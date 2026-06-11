#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
vector<ll> pw2(62,1);vector<ll> pw10(19,1);

vector<vector<ll> > memo(11,vector<ll>(11,INF));
int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    ll N,M; cin>>N>>M;
    ll ans=0;
    vector<vector<char> > field_A(N,vector<char>(N));
    vector<vector<char> > field_B(M,vector<char>(M));
    rep(i,N){
        string tmp; cin>>tmp;
        rep(j,N) field_A[i][j]=tmp[j];
    }
    rep(i,M){
        string tmp; cin>>tmp;
        rep(j,M) field_B[i][j]=tmp[j];
    }
    
    //(i,j)
    rep(i,N-M+1)rep(j,N-M+1){
        bool c=true;
        rep(k,M)rep(l,M){
            if(field_B[k][l]!=field_A[i+k][j+l]) c=false;
        }
        
        if(c){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}

