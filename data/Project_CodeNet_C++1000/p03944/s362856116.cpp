#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    int W,H,N;
    cin>>W>>H>>N;
    int xL=0, xR=W, yL=0, yR=H;
    rep(i, N){
        int x,y,a;
        cin>>x>>y>>a;
        if(a == 1) xL = max(x, xL);
        if(a == 2) xR = min(x, xR);
        if(a == 3) yL = max(y, yL);
        if(a == 4) yR = min(y, yR);
    }

    cout << ((xR-xL)<=0 || (xR-xL)<= 0 ? 0 : (xR-xL)*(yR-yL))  << endl;
}
