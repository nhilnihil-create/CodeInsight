// https://atcoder.jp/contests/abc059/tasks/abc059_b
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
    string A, B;
    cin >> A >> B;
    if (A.size() > B.size())
    {
        cout << "GREATER" << endl;
        return 0;
    }
    else if (A.size() < B.size())
    {
        cout << "LESS" << endl;
        return 0;
    }
    else
    {
        REP(i, A.size())
        {
            if (A[i] > B[i])
            {
                cout << "GREATER" << endl;
                return 0;
            }
            else if (A[i] < B[i])
            {
                cout << "LESS" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
        return 0;
    }
    
    return 0;
}
