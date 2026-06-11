#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
int main(){
    string s; cin >> s;
    int n = s.size(), p = 0, g = 0, ans = 0;
    rep(i, 0, n){
        if (s[i]=='p'){
            if (p < g) p++;
            else ans--, g++;
        }else {
            if (p < g) ans++, p++;
            else g++;
        }
    }
    cout << ans << endl;
    return 0;
}