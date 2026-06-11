#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    vector<lli> a(n);
    rep(i, n) cin >> a[i];
    lli ans = 0;
    rep(i, n){
        if(a[i] == 0) continue;
        //a(i-1), a(i)
        if(i > 1){
            if(a[i-1] > 0){
                lli p = min(a[i-1], a[i]);
                a[i-1]-=p;
                a[i]-=p;
                ans+=p;
            }
        }
        //a(i), a(i)
        ans+=a[i]/2;
        a[i]%=2;

        //a(i), a(i+1)
        if(i < n-1){
            if(a[i+1] > 0){
                lli p = min(a[i+1], a[i]);
                a[i+1]-=p;
                a[i]-=p;
                ans+=p;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
