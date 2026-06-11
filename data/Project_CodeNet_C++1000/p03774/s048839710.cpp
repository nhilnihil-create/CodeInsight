#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int n,m;
    cin >> n >> m;
    ll a[n],b[n];
    ll c[m],d[m];
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,m) cin >> c[i] >> d[i];
    rep(i,n){
        int check;
        ll min_mhtn = INF;
        rep(j,m){
            if((abs(a[i]-c[j])+abs(b[i]-d[j]))<min_mhtn){
                check = j;
                min_mhtn = abs(a[i]-c[j])+abs(b[i]-d[j]);
            }
        }
        cout << check+1 << endl;
    }
    return 0;
}