#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;


int main(void)
{
    IOS
    const int C = 26;
    string S; cin >> S;
    vector<int> cnt(C), mx(C);

    REP(i,S.size()) {
        int c = S[i] - 'a';
        REP(j,C) {
            if (j == c) {
                mx[j] = max(mx[j],cnt[j]);
                cnt[j] = 0;
            } else {
                cnt[j]++;
            }
        }
    }
    REP(i,C) {
        mx[i] = max(mx[i],cnt[i]);
    }

    OUT(*min_element(ALL(mx)));


    return 0;
}