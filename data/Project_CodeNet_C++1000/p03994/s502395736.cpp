// 問題の URL を書いておく
// 

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

//#define ENABLE_PRINT

#if defined(ENABLE_PRINT)

#define Print(v) \
do {\
    cout << #v << ": " << v << endl; \
}while(0)

#define PrintVec(v) \
do {\
    for(int __i = 0; __i < v.size(); ++__i) \
    { \
        cout << #v << "[" << __i << "]: " << v[__i] << endl; \
    }\
}while(0)

#else

#define Print(v) ((void)0)
#define PrintVec(v) ((void)0)

#endif

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

int nums[100005];

int main(int, const char**)
{
    string s;
    cin >> s;
    int K;
    cin >> K;
    rep(i, (int)s.size())
    {
        nums[i] = s[i] - 'a';
    }
    int k = K;
    string ans = "";
    rep(i, (int)s.size() - 1)
    {
        auto t = (26 - nums[i]) % 26;
        if(k >= t)
        {
            k -= t;
            ans += 'a';
        }
        else
        {
            ans += s[i];
        }
    }
    auto lastNum = (nums[s.size() - 1] + k) % 26;
    ans += (char)('a' + lastNum);

    cout << ans << endl;

    return 0;
}
