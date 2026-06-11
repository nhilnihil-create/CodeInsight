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
    int h, w;
    cin >> h >> w;
    int n; cin >> n;
    vector<int> c(n);
    REP(i,n) cin >> c[i];

    vector<vector<int>> ans(h,vector<int>(w));
    int x = 0, y = 0;
    const int R=0,D=1,L=2,U=3;
    int dir=0;

    REP(i,n) {
        int a = i+1;
        int b = c[i];
        REP(j,b) {
            ans[y][x] = a;
            switch (dir)
            {
            case R:
                if (x == w-1 || ans[y][x+1] !=0 ) dir++;
                break;
            case D:
                if (y == h-1 || ans[y+1][x] !=0 ) dir++;
                break;
            case L:
                if (x == 0 || ans[y][x-1] !=0 ) dir++;
                break;
            case U:
                if (y == 0 || ans[y-1][x] !=0 ) dir=0;
                break;
            default:
                break;
            }

            switch (dir)
            {
            case R:
                x++;
                break;
            case D:
                y++;
                break;
            case L:
                x--;
                break;
            case U:
                y--;
                break;
            default:
                break;
            }
        }
    }

    for(auto v:ans) {
        REP(i,v.size()-1) cout << v[i] << " ";
        cout << v.back() << endl;
    }

    return 0;
}