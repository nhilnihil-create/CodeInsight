#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main()
{
    string sa, sb, sc;
    cin >> sa;
    cin >> sb;
    cin >> sc;
    int peo = 0;
    int n = sa.size() + sb.size() + sc.size();
    string ans;
    rep(i, n) {
        int npeo = 0;
        if(peo == 0 && sa == "") {
            ans = "A";
            break;
        }
        if(peo == 1 && sb == "") {
            ans = "B";
            break;
        }
        if(peo == 2 && sc == "") {
            ans = "C";
            break;
        }
        if(peo == 0) {
            if(sa[0] == 'a') npeo = 0;
            if(sa[0] == 'b') npeo = 1;
            if(sa[0] == 'c') npeo = 2;
            sa.erase(0, 1);
        }
        if(peo == 1) {
            if(sb[0] == 'a') npeo = 0;
            if(sb[0] == 'b') npeo = 1;
            if(sb[0] == 'c') npeo = 2;
            sb.erase(0, 1);
        }
        if(peo == 2) {
            if(sc[0] == 'a') npeo = 0;
            if(sc[0] == 'b') npeo = 1;
            if(sc[0] == 'c') npeo = 2;
            sc.erase(0, 1);
        }
        peo = npeo;
    }
    cout << ans << endl;
    return 0;
}