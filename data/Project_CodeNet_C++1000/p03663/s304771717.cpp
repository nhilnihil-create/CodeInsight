#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define rt return
using dbl = double;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

char ask(ll n) {
    cout << "? " << n << endl;
    char ans;
    cin >> ans;
    return ans;
}

void bye(ll n) {
    cout << "! " << n << endl;
    exit(0);
}

// 10^x (x>=0)
void sub() {
    const ll mi = 9;
    if (ask(mi) == 'Y') { // mi > N(値)
        bye(1);
    }

    // 10<=N<=10^9
    for (int n = 1e9; n >= 10; n /= 10) {
        if (ask(n - 1) == 'N') {
            bye(n);
        }
    }
}

int main(){
    const ll ma = 1e17;
    if (ask(ma) == 'Y') { // 10^17のほうが辞書順でNより大きい
        sub();
    }

    string s = "999999999999999999";
    FOR(i, 1, 10) {
        s[0] = '0' + i;
        ll n = stoll(s);
        if (ask(n) == 'Y')break;
    }
    FOR(i, 1, 10) {
        int ub = 9, lb = -1, mid;
        while (ub - lb > 1) {
            mid = (lb + ub) / 2;
            s[i] = ('0' + mid);
            ll n = stoll(s);
            (ask(n) == 'Y' ? ub : lb) = mid;
        }
        s[i] = '0' + ub;
    }

    // 桁数
    for (int i = 1e9, d = 10; i >= 1; i /= 10, --d) {
        if (ask(i) == 'Y') {
            bye(stoll(s.substr(0, d)));
        }
    }
}
