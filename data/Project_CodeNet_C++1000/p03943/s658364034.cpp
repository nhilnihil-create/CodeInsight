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
    vector<ll> a(3);
    rep(0, i, 3)
    {
        cin >> a.at(i);
    }
    sort(all(a));
    if (a.at(0) + a.at(1) == a.at(2))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}