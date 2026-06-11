#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    vector<bool> game(400,true);
    int n,m; cin>>n>>m;
    int a[310][310]={};
    rep(i,n){
        rep(j,m){
            cin>>a[i][j];
        }
    }
    int ans=INF;
    vector<int> idx(n,0);
    rep(g,m){
        multiset<int> c;
        rep(i,n){

            c.insert(a[i][idx[i]]);
        }
        int tmp=0,nxt;
        rep(i,301){
            if(tmp<c.count(i)){
                tmp=c.count(i);
                nxt=i;
            }
        }
        game[nxt]=false;
        ans=min(tmp,ans);
        rep(i,n){
            if(idx[i]>=m) continue;
            while(!game[a[i][idx[i]]]) idx[i]++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
