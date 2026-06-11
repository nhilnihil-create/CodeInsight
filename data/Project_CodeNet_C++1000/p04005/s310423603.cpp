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
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    ll A[3]; cin >> A[0] >> A[1] >> A[2];
    sort(A, A + 3);
    if(A[0] % 2 == 0 || A[1] % 2 == 0 || A[2] % 2 == 0) {
        cout << 0 << endl;
    }else {
        cout << A[0] * A[1] << endl;
    }
}
