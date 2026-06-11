#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(0, i, N)
    {
        cin >> A.at(i);
        A.at(i)--;
    }
    int ans = 0;
    rep(0, i, N)
    {
        if (A.at(A.at(i)) == i)
        {
            ans++;
        }
    }
    cout << ans / 2 << endl;
}