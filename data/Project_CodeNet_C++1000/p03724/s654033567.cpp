#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;

int main(){

    int n,m; cin >> n >> m;
    vector<int> ab(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        --a;--b;
        ++ab.at(a);++ab.at(b);
    }
    rep(i,n){
        if(ab.at(i)%2){
            cno;
            return 0;
        }
    }
    cyes;
    return 0;
}
