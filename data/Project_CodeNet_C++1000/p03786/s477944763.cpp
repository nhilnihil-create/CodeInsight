#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
int n;
vector<ll> a(n);

bool ok(int x){
    ll sz = a[x];
    rep(i,n){
        if(i==x) continue;
        if(a[i] <= 2*sz) sz += a[i];
        else return false;
    }
    return true;
}

int main(){
    cin >> n;
    a.resize(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int left = -1,right = n;
    while(right - left > 1){
        int mid = (left + right)/2;
        if(ok(mid)) right= mid;
        else left = mid;
    }
    cout << n-right << endl;
    return 0;
}