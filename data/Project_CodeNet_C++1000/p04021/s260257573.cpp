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

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<P> p(n);
    rep(i,n) p[i] = P(a[i],i);
    sort(p.begin(),p.end());
    int ans = 0;
    rep(i,n){
        if(abs(p[i].second-i)%2==1) ++ans;
    }
    cout << (ans/2) << endl;
    return 0;
}