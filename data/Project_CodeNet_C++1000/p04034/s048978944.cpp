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
    int N, M;
    cin >> N >> M;
    vector<int> ball(N,1);
    vector<bool> red(N);
    red[0] = true;

    REP(i,M) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (red[x]) red[y] = true;
        ball[x]--; ball[y]++;
        if (ball[x] == 0) red[x] = false;
    }

    OUT(count(ALL(red),true));

    return 0;
}