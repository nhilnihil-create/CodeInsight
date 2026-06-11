#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define rep1(i, n) for (int i = 1; i < int(n); ++i)
#define repx(i, x, n) for (int i = int(x); i < int(n); ++i)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define ALL(n) begin(n), end(n)
#define IN(a, x, b) ((a) <= (x) && (x) < (b))
#define OUT(a, x, b) ((x) < (a) || (x) < (b))
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const ll MOD = 1000000007;

int main()
{
    int N;
    cin >> N;
    // vector<int> a;
    set<int> s;

    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        // a.push_back(tmp);
        s.insert(tmp);
    }
    // sort(a.begin(), a.end());
    // cout << s.size() << endl;
    if ((N - s.size()) % 2 == 0)
    {
        cout << s.size() << endl;
    }
    else
    {
        cout << s.size() - 1 << endl;
    }

    return 0;
}
