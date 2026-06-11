#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    map<int,int> mp;
    rep(i,n){
        int p;cin>>p;p--;
        mp[p]=i+1;
    }
    vector<int> a(n,0),b(n,0);
    a[0]=mp[0];
    b[n-1]=mp[n-1];
    rep(i,n-1){
        a[i+1]=a[i]+mp[i+1];
        b[n-i-2]=b[n-1-i]+mp[n-i-2];
    }
    rep(i,n)cout<<a[i]<<" ";
    cout<<endl;
    rep(i,n)cout<<b[i]<<" ";
    cout<<endl;
}