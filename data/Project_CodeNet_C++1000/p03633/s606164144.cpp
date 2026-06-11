#include <bits/stdc++.h>
using namespace std;

using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)

lint gcd(lint a, lint b)
{
    if (a < b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    return b ? gcd(b, a % b) : a;
}

lint lcm(lint a, lint b)
{
    return (a  / gcd(a, b))*b;
}

int main()
{
    lint n;cin >> n;
    lint ans=1;
    REP(i,n){
        lint t;
        cin >> t;
        ans =lcm(ans, t);
    }
    cout << ans << "\n";
    return 0;
}