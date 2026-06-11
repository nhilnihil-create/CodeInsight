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
    ll H,W,N;
    cin >>W>>H>>N;

    vector<vector<bool>>B(H,vector<bool>(W));

    rep(i,N){
        ll x,y,a;
        cin>>x>>y>>a;
        if(a==1){
            rep(j,H){
                rep3(k,0,x){
                    B[j][k]=1;
                }
            }
        }else if(a==2){
            rep(j,H){
                rep3(k,x,W){
                    B[j][k]=1;
                }
            }
        }else if(a==3){
            rep(k,W){
                rep3(j,0,y){
                    B[j][k]=1;
                }
            }
        }else if(a==4){
            rep(k,W){
                rep3(j,y,H){
                    B[j][k]=1;
                }
            }
        }
    }
    ll ans=0;

    rep(i,H){
        rep(j,W){
            //cout<<B[H-i-1][j];
            if(B[i][j]==0){
                ans++;
            }
        }
        //cout<<endl;
    }
    cout << ans << endl;


    return 0;
    

}