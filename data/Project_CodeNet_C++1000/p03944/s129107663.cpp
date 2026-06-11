#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int w,h,n;
    cin >> w >> h >> n;
    int ww = 0, hh = 0;
    rep(i,n){
        int x,y,a;
        cin >> x >> y >> a;
        if(a == 1){
            ww = max(ww,x);
        }
        if(a == 2){
            w = min(w,x);
        }
        if(a == 3){
            hh = max(hh,y);
        }
        if(a == 4){
            h = min(h,y);
        }
    }
    //cout << ww << " " << w << endl;
    //cout << hh << " " << h << endl;
    if(h <= hh || ww >= w){
        cout << 0 << endl;
    }else cout << (hh-h)*(ww-w) << endl;
    return 0;
}