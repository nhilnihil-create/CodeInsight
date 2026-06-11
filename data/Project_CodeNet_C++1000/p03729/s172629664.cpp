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
#define rep(i,x) for(int i=0;i<x;i++)
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
}

int main(){
    string A, B, C;
    cin >> A >> B >> C;
    ll a = A.size();
    ll b = B.size();
    ll c = C.size();
    if (A[a - 1] == B[0] && B[b - 1] == C[0])cout << "YES" << endl;
    else cout << "NO" << endl;
}