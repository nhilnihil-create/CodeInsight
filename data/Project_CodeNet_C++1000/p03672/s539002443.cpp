#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>
#include <stdio.h>
#include <numeric>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define MOD 1000000007 //10^9+7
#define TEN5 100000 //10^5
#define TEN9 1000000000 //10^9
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int INF = numeric_limits<int>::max();

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

//greatest common divisor
long long gcd(ll a, ll b) 
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

//least common multiple
long long lcm(ll a, ll b)
{
    return a / gcd(a, b) * b ;
}

int main()
{
    string s;
    cin >> s;
    s = s.substr(0, s.length() - 1);
    while(s.length() != 1) {
        if (s.length() % 2 == 0) {
            int flag = 0;
            rep(i,s.length()/2) {
                if (s[i] != s[s.length()/2 + i])
                    flag = 1;
            }
            if (flag == 0) {
                break;
            }
        }
        s = s.substr(0, s.length() - 1);
    }

    cout << s.length() << endl;
    return 0;
}

