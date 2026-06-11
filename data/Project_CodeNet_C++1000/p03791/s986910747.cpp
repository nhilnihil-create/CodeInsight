#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

ll f[100010];

void calc(){
    f[0] = 1;
    rep(i, 1, 100010) {
        f[i] = f[i - 1] * i;
        f[i] %= mod;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    calc();
    ll ans = 1;

    int num = 0;
    
    rep(i, N){
        if(i == 0){
            num++;
            continue;
        }
        if(A[i - 1] >= num * 2 - 1){
            num++;
        }
        else{
            ans *= num;
            ans %= mod;
            
        }
//        cout << i <<  "," << A[i] << "," << num << ":" << ans << endl;
    }
    ans *= f[num];
    ans %= mod;
    
    output(ans);
    
    
    return 0;
}