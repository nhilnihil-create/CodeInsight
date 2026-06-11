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
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    deque<ll> dq;
    ll a;
    rep(0, i, N)
    {
        cin >> a;
        if (i % 2 == 0)
        {
            dq.push_back(a);
        }
        else
        {
            dq.push_front(a);
        }
    }
    if (N % 2 == 0)
    {
        while (!dq.empty())
        {
            cout << dq.front() << ' ';
            dq.pop_front();
        }
        cout << endl;
    }
    else
    {
        while (!dq.empty())
        {
            cout << dq.back() << ' ';
            dq.pop_back();
        }
        cout << endl;
    }
}