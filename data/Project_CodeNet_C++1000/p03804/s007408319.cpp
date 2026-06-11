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
    ll N,M;
    cin >>N>>M;
    vector<string>A(N),B(M);

    rep(i,N){
        cin>>A[i];
    }
    rep(i,M){
        cin>>B[i];
    }
    rep(i,N-M+1){
        rep(j,N-M+1){
            ll flag=0;
            rep(k,M){
                rep(m,M){
                    if(A[i+k][j+m]!=B[k][m]){
                        flag=1;
                        break;
                    }

                }
                if(flag==1){
                    break;
                }
                if(k==M-1){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    
    cout <<"No" << endl;


    return 0;
    

}