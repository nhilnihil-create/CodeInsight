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
//#define P pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    ll N, A, B; cin >> N >> A >> B;
    if(A > B) {
        cout << 0 << endl;
    }else if(A == B || N == 2) {
        cout << 1 << endl;
    }else if(N == 1) {
        cout << 0 << endl;
    }else {
        cout << (N - 2) * (B - A) + 1 << endl;
    }
}
