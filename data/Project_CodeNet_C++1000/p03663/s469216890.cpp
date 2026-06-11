#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int ans = 1000000;
string sans;

char ask(string xs){
    ll x = 0;
    REP(i,xs.length()) x = 10 * x + (xs[i] - '0');
    if ((ans <= x && sans <= xs) || (ans > x && sans > xs)) return 'Y';
    return 'N';
}

int main() {
    int p = ans;
    while (p){
        char c = (p % 10) + '0';
        sans = c + sans;
        p /= 10;
    }

    string s(11,'0');
    REP(i,10){
        int l = 0, r = 10;
        if (i == 0) l = 1;
        while (r - l > 1){
            int m = (l + r) / 2;
            s[i] = m + '0';
            cout << "? " << s << endl;
            char c;
            cin >> c;
            // c = ask(s);
            if (c == 'Y') r = m;
            else l = m;
        }
        s[i] = l + '0';

        string t = s.substr(0,i+1);
        while (t.length() < 10) t += '9';
        cout << "? " << t << endl;
        char c;
        cin >> c;
        // c = ask(t);
        if (c == 'Y') continue;
        string nine(i, '9');
        nine += '8';
        if (s.substr(0,i+1) == nine){
            FOR(j,i+1,10){
                string u = '1' + string(j,'0');
                cout << "? " << u << endl;
                // c = ask(u);
                cin >> c;
                if (c == 'N'){
                    string ans(i+1, '9');
                    while (ans.length() < j) ans += '0';
                    cout << "! " << ans << endl;
                    return 0;
                }
            }
        }
        FOR(j,i+1,10){
            string u(j, '9');
            cout << "? " << u << endl;
            // c = ask(u);
            cin >> c;
            if (c == 'Y'){
                s = s.substr(0,i+1);
                s[i]++;
                while (s.length() < j) s += '0';
                cout << "! " << s << endl;
                return 0;
            }
        }
    }

    FOR(j,1,10){
        string u(j, '9');
        cout << "? " << u << endl;
        // char c = ask(u);
        char c;
        cin >> c;
        if (c == 'Y'){
            string ans = "1";
            while (ans.length() < j) ans += '0';
            cout << "! " << ans << endl;
            return 0;
        }
    }


    return 0;
}