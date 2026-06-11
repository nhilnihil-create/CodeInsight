// https://atcoder.jp/contests/agc016/tasks/agc016_a
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    string s;
    cin >> s;
    set<char> cs;
    for (const char& c : s) cs.insert(c);
    if (cs.size() == 1)
    {
        printf("0\n");
        return 0;
    }
    int ans = s.size() / 2;
    for (const char& c : cs)
    {
        string chunk = s;
        int count = 1;
        bool isRetry = true;
        while (isRetry)
        {
            string str;
            isRetry = false;
            for (int i = 0; i < chunk.size() - 1; ++i)
            {
                if (c == chunk[i] || c == chunk[i + 1])
                {
                    str.push_back(c);
                }
                else
                {
                    // 異なる文字が入っている場合
                    str.push_back(chunk[i]);
                    isRetry = true;
                }
            }

            if (isRetry)
            {
                chunk = str;
                ++count;
            }
        }

        ans = min(ans, count);
    }

    printf("%d\n", ans);
    return 0;
}
