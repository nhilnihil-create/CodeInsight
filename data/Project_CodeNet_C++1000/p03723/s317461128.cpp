#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int ans = 0;
    while(!(A % 2) && !(B % 2) && !(C % 2)) {
        int tmpA = A, tmpB = B, tmpC = C;
        A = (tmpB + tmpC) / 2;
        B = (tmpA + tmpC) / 2;
        C = (tmpA + tmpB) / 2;
        ++ans;
        if(ans > 500000) A = 1, ans = -1;
    }
    cout << ans << endl;
}
