#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
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
    const int I = 64;
    const int D = 10;
    const char Y = 'Y';
    //const char N = 'N';
    const int N = 9; 

    auto qout = [](ll x){cout << "? " << to_string(x) << endl; cout.flush();return;};
    auto aout = [](ll x){cout << "! " << to_string(x) << endl; cout.flush();return;};
    auto qin = []{char c; cin >> c; return c == Y;};

    int n = N;
    int i = 0;
    vector<bool> visit(D);
    vector<bool> yn(D);

    ll ans = 1e9;
    bool one = false;
    while(true) {
        qout(ans);
        i++;
        if (qin()) {
            if (n == N) one = true;
            break;
        } 
        ans /= 10;
        n--;
    }

    if (one) {
        while(n > 0) {
            qout(ans-1);
            i++;
            if (!qin()) {
                aout(ans);
                return 0;
            }
            ans /= 10;
            n--;
        }
        aout(ans);
        return 0;
    }

    bool nl = false;
    int x = 1;
    int d = 8;
    ans = 0;
    while(i < I) {
        if(nl) {
            visit = vector<bool>(D);
            yn = vector<bool>(D);
            x = 0;
            d = 9;
            nl = false;
        }
        visit[x] = true;
        if (n == 0) {
            qout(ans*100 + x*10);
        } else {
            qout(ans*10 + x);
        }
        bool b = qin();
        yn[x] = b;
        if (b) {
            if (n == 0) {
                aout(ans*10+x);
                return 0;
            } else if (x == 9) {
                ans = ans * 10 + x;
                n--;
                nl = true;
            } else if (visit[x+1] && !yn[x+1]) {
                ans = ans * 10 + x;
                n--;
                nl = true;
            } else {
                x += d;
            }
        } else {
            if (n == 0) {
                x++;
            } else if (visit[x-1] && yn[x-1]) {
                ans = ans * 10 + x-1;
                n--;
                nl = true;
            } else {
                x -= d;
            }
        }

        d /= 2; if (d == 0) d = 1;
        i++;
    }
 
    return 0;
}
