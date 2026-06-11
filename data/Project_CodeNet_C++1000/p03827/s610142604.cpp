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

int main()
{
    lint n;cin >> n;
    string s;
    cin >> s;
    lint ans = 0,ans2=0;
    REP(i,SZ(s)){
        if(s[i]=='I'){
            ans++;
        }else{
            ans--;
        }
        ans2 = max(ans, ans2);
    }
    cout << ans2 << "\n";
    return 0;
}