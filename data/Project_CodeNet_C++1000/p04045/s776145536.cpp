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

int main(int, const char**)
{
    int N, K;
    cin >> N >> K;
    bool ng[10] = {};
    rep(i, K)
    {
        int a;
        cin >> a;
        ng[a] = true;
    }

    int ans = N;
    while(true)
    {
        int t = ans;
        bool isNg = false;
        while(t != 0)
        {
            auto m = t % 10;
            if(ng[m])
            {
                isNg = true;
                break;
            }
            t /= 10;
        }
        if(!isNg)
        {
            cout << ans << endl;
            return 0;

        }
        ans++;
    }
    return 0;
}
