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

    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    ll cnt = 0;

    rep(i,n-1){
        cnt += a.at(i)/2;
        a.at(i) = a.at(i)%2;
        int temp;
        temp = min(a.at(i),a.at(i+1));
        cnt += temp;
        a.at(i+1) -= temp;
    }
    cnt += a.at(n-1)/2;
    cout << cnt << endl;
    return 0;
}
