// 問題の URL を書いておく
// 

#include <algorithm>
#include <array>
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

using ll = int64_t;

int main(int, const char**)
{
    string x;
    cin >> x;
    vector<char> s(x.size());
    s.resize(0);
    for(auto c : x)
    {
        s.push_back(c);
        if(s.size() >= 2)
        {
            if(s[s.size() - 1] == 'T' && s[s.size() - 2] == 'S')
            {
                s.resize(s.size() - 2);
            }
        }
    }
    cout << s.size() << endl;
    return 0;
}
