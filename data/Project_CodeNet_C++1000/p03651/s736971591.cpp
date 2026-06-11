#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
const int MOD=998244353;
int gcd(int a,int b){
    return (b?gcd(b,a%b):a);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;cin >> n >> k;
    vector<int> a(n);
    int mx=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        chmax(mx,a[i]);
    }
    int g=0;
    for(int i=0;i<n;i++){
        g=gcd(g,a[i]);
    }
    if(k<=mx&&k%g==0){
        cout << "POSSIBLE" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}