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
void printv(vector<T> vc)
{
    for (auto e : vc)
        cout << e << " ";
    cout << endl;
}

template <class T>
void printvv(vector<T> vvc)
{
    for (auto vc : vvc)
    {
        for (auto e : vc)
            cout << e << " ";
        cout << endl;
    }
}

template <class T>
void printvp(vector<pair<T, T> > vp)
{
    for (auto pT : vp)
        cout << pT.first << " " << pT.second << endl;
}

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vs v = {"dream", "dreamer", "erase", "eraser"};
    for (int i = 0; i < v.size(); ++i) {
        reverse(v[i].begin(), v[i].end());
    }

    auto a = true;
    for (int i = 0; i < s.size();) {
        auto b = false;
        for (int j = 0; j < v.size(); ++j) {
            const auto target = v[j];
            if (s.substr(i, target.size()) == target) {
                i += target.size();
                b = true;
            }
        }
        if (!b) {
            a = false;
            break;
        }
    }

    cout << (a ? "YES" : "NO") << endl;

    return 0;
}
