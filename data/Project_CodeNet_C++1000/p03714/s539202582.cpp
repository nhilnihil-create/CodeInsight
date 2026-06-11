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
    cin >>N;
    vector<ll>L(N),C(N),R(N);
    ll ans=0;
    priority_queue<ll, vector<ll>, greater<ll>> QL;
    priority_queue<ll, vector<ll>, less<ll>> QR;
    rep(i,N){
        cin>>L[i];
        QL.push(L[i]);
        ans+=L[i];
    }

    rep(i,N)cin>>C[i];

    rep(i,N){
        cin>>R[i];
        QR.push(R[i]);
        ans-=R[i];
    }

    sort(all(L));
    sort(all(R));
    reverse(all(R));
    vector<ll>SL(N+1),SC_L(N+1),SR(N+1);
    
    rep(i,N){
        QL.push(C[i]);
        ll tmp=QL.top();
        QL.pop();
        SL[i+1]=SL[i]+C[i]-tmp;

    }

    rep(i,N){
        QR.push(C[N-i-1]);
        ll tmp=QR.top();
        QR.pop();
        SR[i+1]=SR[i]+C[N-i-1]-tmp;

    }

    ll d=0;

    rep(i,N+1){
        chmax(d,SL[i]-SR[N-i]);
    }


    cout << ans+d << endl;


    return 0;
    

}