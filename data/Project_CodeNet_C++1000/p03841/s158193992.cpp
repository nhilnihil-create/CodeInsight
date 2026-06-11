#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define FOR(i, a, b) for(decltype(b) i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

#ifdef INPUT
#include <sstream>
stringstream input(R"(
6
)");
#define cin input
#endif

int main()
{
	int n;
	cin >> n;

    map<int, int> x;

    vector<int> pre(n), post(n);

    vector<int> res;
    res.reserve(n * n);

    REP (i, n)
    {
        int a;
        cin >> a;
        x[a] = i;
        pre[i] = i;
    }

    auto it = x.begin();
    auto itpre = x.begin();
    auto itpost = x.begin();
    REP (i, n * n)
    {
        if (it != x.end() && it->first == i + 1)
        {
            if (pre[it->second])
                break;
            res.push_back(it->second);
            post[it->second] = n - it->second - 1;
            ++it;
        } else
        {
            while (itpre != x.end() && (it == x.end() || itpre != x.end() || itpre->first <= it->first) && pre[itpre->second] == 0)
                ++itpre;
            if (itpre == x.end() || pre[itpre->second] == 0)
            {
                while (itpost != x.end() && post[itpost->second] == 0)
                    ++itpost;
                if (itpost == x.end() || post[itpost->second] == 0)
                    break;
                res.push_back(itpost->second);
                --post[itpost->second];
            } else
            {
                res.push_back(itpre->second);
                --pre[itpre->second];
            }
        }
    }

	if (res.size() == n * n)
	{
		cout << "Yes" << endl;
        REP (i, n * n - 1)
            cout << (res[i] + 1) << ' ';
        cout << (res[n * n - 1] + 1) << endl;
	} else
		cout << "No" << endl;

	return 0;
}
