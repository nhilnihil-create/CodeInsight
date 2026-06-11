#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define yes(n) cout << ((n) ? "yes" : "no") << endl

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;
const vector<int> di = {-1,  0, 1, 0};
const vector<int> dj = { 0, -1, 0, 1};

void chmin(int &a, int b) { if (a > b) a = b; }

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }


int main(){
    int n;
    cin >> n;

    int two = 0;
    int four = 0;
    int odd = 0;

    rep(i, n) {
        ll a;
        cin >> a;
        if (a % 4 == 0) four++;
        else if (a % 2 == 0) two++; 
        else odd++;
    }

    if (!two) Yes(four + 1 >= odd);
    else Yes(four >= odd);
}
