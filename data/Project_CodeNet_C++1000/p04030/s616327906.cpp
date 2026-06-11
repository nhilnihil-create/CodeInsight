//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    string s;
    cin >> s;
    size_t N = s.size();
    string ans;
    REP(i, N)
    {
        if (s[i] == '0')
        {
            ans.push_back('0');
        }
        else if (s[i] == '1')
        {
            ans.push_back('1');
        }
        else
        {
            if (ans.empty()) continue;
            else ans.pop_back();
        }
        
    }
    cout << ans << endl;
    return 0;
}
