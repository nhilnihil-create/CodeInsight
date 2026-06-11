#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
int main(){
    int ans = 1;
    string s; cin >> s;
    char tmp = s[0];
    rep(i, 1, s.size()){
        if (s[i]!=tmp) ans++, tmp = s[i];
    }
    cout << ans - 1 << endl;
    return 0;
}