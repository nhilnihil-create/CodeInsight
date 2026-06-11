#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
#include <cmath>
#include <map>
#include <tuple>
#include <complex>

#define MOD 1000000007

using namespace std;

typedef long long ll;

typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<string> vs;

typedef pair<ll, ll> pll;
typedef pair<int, int> pi;

typedef vector<pll> vpl;
typedef vector<pi> vpi;

typedef queue<ll> ql;
typedef queue<int> qi;

template <class T>
void printv(vector<T> v)
{
    for (auto e : v)
        cout << e << " ";
    cout << endl;
}

template <class T>
void printvv(vector<T> vv)
{
    for (auto v : vv)
    {
        for (auto e : v)
            cout << e << " ";
        cout << endl;
    }
}

template <class T>
void printvp(vector<pair<T, T> > vp)
{
    for (auto p : vp)
        cout << p.first << " " << p.second << endl;
}

int main() {
    string S;
    cin >> S;

    const auto size = S.size()-1;
    ll ans = 0;
    for (int bit = 0; bit < (1<<size); ++bit) {
        ll value = 0;
        ll digit = 0;
        for (int j = size; j >= 0; --j) {
            const auto a = S[j] - '0';
            value += a * pow(10, digit);
            if (bit & (1 << (size-j))) digit = 0;
            else ++digit;
        }
        ans += value;
    }

    cout << ans << endl;

    return 0;
}
