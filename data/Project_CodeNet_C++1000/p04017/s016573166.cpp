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

const int daymax=100010;
const int LOG=17;
int n;
vector<ll> x;
ll l;
ll table[100010][20];

void fill(vector<ll> v){
    //table[i][k] : iの2^k日で行けるindex
    table[n-1][0]=-1;
    rep(i,n-1){
        int idx=lower_bound(ALL(v),v[i]+l+1)-v.begin();
        idx--;
        table[i][0]=idx;
    }
    for(int k=0;k<LOG;k++){
        for(int i=0;i<n;i++){
            if(table[i][k]<0) table[i][k+1]=-1;
            else table[i][k+1]=table[table[i][k]][k];
        }
    }
}

int can_go(int day,int pos){
    //day日でposからどこまで行けるか
    if(day==0) return pos;
    int ret=pos;
    for(int i=LOG-1;i>=0;i--){
        if((day>>i)&1){
            ret=table[ret][i];
        }
        if(ret<0) break;
    }
    
    if(ret<0) ret=n-1;
    // cout<<"Day : "<<day<<" pos "<<pos<<" can go "<<ret<<endl;
    return ret;
}

int f(int a,int b){
    int lw=0,hi=daymax;
    while(hi-lw>0){
        int mid=(lw+hi)/2;
        if(can_go(mid,a)>=b) hi=mid;
        else lw=mid+1;
    }
    return hi;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    //ダブリングテーブル構築して殺せそう
    cin>>n;
    x.resize(n);
    rep(i,n) cin>>x[i];
    cin>>l;

    fill(x);
    // rep(i,n){
    //     rep(j,5){
    //         cout<<table[i][j]<<' ';
    //     }cout<<endl;
    // }

    vector<int> ans;
    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;a--,b--;
        if(a>b) swap(a,b);
        ans.push_back(f(a,b));
    }
    for(auto x:ans){
        cout<<x<<endl;
    }
    return 0;
}
