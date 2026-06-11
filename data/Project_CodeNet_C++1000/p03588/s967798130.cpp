#include<bits/stdc++.h>                                                                                               
 
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define int long long
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;

signed main(){
    int n;
    cin >> n;
    int minv = INF,maxv = -10;
    int miv = 0,mav = 0;
    int a,b;
    rep(i,n){
        cin >> a >> b;
        if(minv > a){ 
            minv = a;
            miv = b;
        }
        if(maxv < a){ 
            maxv = a;
            mav = b;
        }
    }   
    cout << maxv + mav << '\n';
    return 0;
}
