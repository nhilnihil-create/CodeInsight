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
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N, 0);
    // flag=1なら単調増加,flag=0なら単調減少
    ll ans = 1, flag = -1;
    rep(0, i, N)
    {
        cin >> A.at(i);
        if (i == 0)
        {
            continue;
        }
        if (flag == -1)
        {
            if (A.at(i) - A.at(i - 1) < 0)
            {
                flag = 0;
            }
            if (A.at(i) - A.at(i - 1) > 0)
            {
                flag = 1;
            }
            continue;
        }
        // 単調増加だったのに単調減少に切り替わった
        if ((A.at(i) - A.at(i - 1) < 0) && flag == 1)
        {
            ans++;
            flag = -1;
        }
        // 単調減少だったのに単調増加になった
        if ((A.at(i) - A.at(i - 1) > 0) && flag == 0)
        {
            ans++;
            flag = -1;
        }
    }

    cout << ans << endl;
}