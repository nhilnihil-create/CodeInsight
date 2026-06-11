#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
int main(){
    int k, s, ans = 0; sc(k), sc(s);
    vector<int> v(k+1);
    rep(i, 0, k+1) v[i] = i;
    rep(i, 0, k+1){
        if (s < i) break;
        rep(j, 0, k+1){
            if (s < i+j) break;
            if (i+j+k < s) continue;
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}