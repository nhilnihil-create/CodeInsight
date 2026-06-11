#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll A, B, C;
    cin >> A >> B >> C;
    map<ll, ll> m;
    m[A]++;
    m[B]++;
    m[C]++;
    if (m[5] == 2 && m[7] == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}