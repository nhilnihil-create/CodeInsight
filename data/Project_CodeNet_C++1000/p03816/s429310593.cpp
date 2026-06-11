#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

int main(void)
{
    IOS
    const int N = 1e7+1;
    int n; cin >> n;
    vector<int> m(N);
    REP(i,n) {
        int x;
        cin >> x;
        m[x]++;
    }
    int cnt = 0;
    REP(i,N) if (m[i] != 0) cnt++; 

    cout << ( cnt % 2 == 0 ? cnt -1 : cnt ) << endl;

    return 0;
}