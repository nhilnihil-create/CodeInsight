#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<int,int> ;
const int INF = 1e9;
const int MOD = 1000000007;

int gcd(int a,int b){
    if(b ==0) return a;
    return gcd(b,a%b);
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int m = 0;
    int mx = 0;
    rep(i,n) m = gcd(m,a[i]),mx = max(a[i],mx);
    cout << ( k%m ==0  && k <= mx ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    return 0;
}