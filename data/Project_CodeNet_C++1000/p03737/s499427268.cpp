#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<iomanip>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1e9 + 7;
const int MAX = 1e9;
const ll LLMAX = 1e18;
const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const double PI = acos(-1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

int main() {
    string A, B, C; cin >> A >> B >> C;
    
    // cout << char(toupper(A[0])) << char(toupper(B[0])) << char(toupper(C[0])) << endl;

    // 小文字を大文字に変える
    char diff = 'a' - 'A'; // A < a
    cout << char(A[0] - diff) << char(B[0] - diff) << char(C[0] - diff) << endl;
    return 0;
}
