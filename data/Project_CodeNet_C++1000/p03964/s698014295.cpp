#include <bits/stdc++.h>
using namespace std;
#define dbg(x) #x "=" << x << " "
#define fore(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int n;
    cin >> n;
    ll A, B, a, b;
    cin >> A >> B;
    while (--n) {
        cin >> a >> b;
        ll k = max((A+a-1)/a, (B+b-1)/b);
        A = a*k;
        B = b*k;
    }
    cout << A+B << endl;
}
