#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
int main(){
    int w,h;
    cin >> w >> h;
    long long p[w],q[h];
    long long ans = 0;
    rep(i,w){
        cin >> p[i];
        ans+=p[i];
    }
    rep(i,h){
        cin >> q[i];
        ans+=q[i];
    }
    sort(q,q+h);
    long long sumq[h+1];
    sumq[0]=0;
    rep(i,h) sumq[i+1]=sumq[i]+q[i];
    rep(i,w){
        auto itr = lower_bound(q,q+h,p[i]);
        int k = itr-q;
        ans+=(sumq[k]+(h-k)*p[i]);
    }
    cout << ans << endl;
}