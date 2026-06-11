#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <cstdlib>
#include <iomanip>
#define rep(i,x) for(ll i=0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
using ld = long double;
using ll = long long;
const ll INF = 10010010010;
typedef pair<ll, ll> P;
using graph = vector<vector<ll>>;
const ll mod = 1000000007;
ll gcd(ll a, ll b) {//a>b
    if (a < b)swap(a, b);
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}/*フィボナッチテンプレ
ll memo[50];
ll fibo(ll n) {
    if (memo[n] != 0)return memo[n];
    if (n <= 1)return memo[n] = n;
    else return memo[n] = fibo(n - 1) + fibo(n - 2);
}
*/
bool isp(ll n) {
    bool res = true;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res = false;
            break;
        }
    }
    return res;
}
ll ctoi(char c) {
    if (c == '0')return 0;
    else if (c == '1')return 1;
    else if (c == '2')return 2;
    else if (c == '3')return 3;
    else if (c == '4')return 4;
    else if (c == '5')return 5;
    else if (c == '6')return 6;
    else if (c == '7')return 7;
    else if (c == '8')return 8;
    else if (c == '9')return 9;
    else return -1;
}int main() {
    ll M, N, O, P, L;//M->0.25 N->0.5 O->1 P->2
    cin >> M >> N >> O >> P >> L;
    ll cheap = min(min(M * 4, N * 2), O);
    if (cheap * 2 <= P) {
        cout << L * cheap << endl;
    }
    else {
        cout << L / 2 * P + L % 2 * cheap << endl;
    }
}