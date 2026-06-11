#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<ll>a(n),t(n);
    rep(i, 0, n)cin >> a[i] >> t[i];
    ll left=a[0], right=t[0];
    rep(i, 1, n){
        if(a[i]>=left && t[i]>=right){
            left = a[i];
            right = t[i];
        }else if(a[i]<left && t[i]>=right){
            ll temp = (left+a[i]-1)/a[i];
            left = a[i]*temp;
            right = t[i]*temp;
        }else if(a[i]>=left && t[i]<right){
            ll temp = (right+t[i]-1)/t[i];
            left = a[i]*temp;
            right = t[i]*temp;
        }else{
            ll tempa = (left+a[i]-1)/a[i];
            ll tempt = (right+t[i]-1)/t[i];
            left = a[i]*max(tempa,tempt);
            right = t[i]*max(tempa,tempt);
        }
        //cout << left << " " << right << endl;
    }
    cout << left+right << endl;
}