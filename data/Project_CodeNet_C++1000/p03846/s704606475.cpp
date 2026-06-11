#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define MOD 1000000007
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

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
    ll N;
    cin >>N;
    vector<ll>A(N);
    ll flag=0;
    if(N%2==0){
       rep(i,N){
            ll a;
            cin>>a;
       
            A[a]++;
            if(a%2==0){
                flag==1;
            }else if(A[a]>2){
                flag=1;
            }
        }
    }else{
        rep(i,N){
            ll a;
            cin>>a;
        
            A[a]++;
            if(a%2==1){
                flag==1;
            }else if(A[a]>2||(a==0&&A[a]>1)){
                flag=1;
            }
        }
    }
    if(flag==1){
        cout<<0<<endl;
    }else{
        cout<<modpow(2,N/2,MOD)<<endl;;
    }



    return 0;
    

}