#include<bits/stdc++.h>
#define int long long
/* #define double long double */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)

signed main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    int cnt = 0;
    int inc = 0;
    int dcr = 0;

    rep(i, n-1){
        int diff = a[i+1] - a[i];
        if(diff < 0){
            if(inc){
                cnt++;
                dcr = 0;
                inc = 0;
                continue;
            }
            inc = 0;
            dcr++;
            /* cout << "dcr "; */
        }else if(diff > 0){
            if(dcr){
                cnt++;
                inc = 0;
                dcr = 0;
                continue;
            }
            dcr = 0;
            inc++;
            /* cout << "inc "; */
        }else{
            if(dcr > 1) dcr++;
            if(inc > 1) inc++;
        }
    }
    /* cout << endl; */

    cout << cnt+1 << endl;
}