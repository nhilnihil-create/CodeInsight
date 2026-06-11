#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using ll = long long;
#define int long long
signed main(void){
    int n,t; cin>>n>>t;
    vector <int> a(n); 
    rep(i,n) cin>>a[i];
    vector <int> right(n); 
    vector <int> left(n); 
    priority_queue <int> q;
    int big=-1;
    for(int i=n-1;i>=0;i--){
        q.push(a[i]);
        big = max(q.top() - a[i], big);
    }
    int ans = 0;
    map <int,int> ma;
    rep(i,n){
        ma[a[i]]++;
        if(ma[a[i]-big]) ans++;
    }
    cout<<ans<<endl;
}
