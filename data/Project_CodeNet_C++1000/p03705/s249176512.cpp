#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<int,int> P;


int main(){
    int n,a,b; cin >> n >> a >> b;
  
    if(a>b||(n==1&&a!=b)){
        cout << 0 << endl;
        return 0;
    }
    if(a==b||n==2){
        cout << 1 << endl;
        return 0;
    }
    n-=2;
    ll MAX=0,MIN=0;
    rep(i,n){
        MAX+=b;
        MIN+=a;
    }

    cout << MAX-MIN+1 << endl;
    return 0;
}
