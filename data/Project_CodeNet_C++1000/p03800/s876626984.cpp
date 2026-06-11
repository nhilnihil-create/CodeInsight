#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


void add_animal(char s, string &t)
{
    int lt = t.length();
    // cout << lt << s << t[lt-2] << t[lt-2] << endl;
    if (s == 'o' && t[lt - 2] == 'S' && t[lt - 1] == 'S')
        t += 'S';
    else if (s == 'x' && t[lt - 2] == 'S' && t[lt - 1] == 'S')
        t += 'W';
    else if (s == 'o' && t[lt - 2] == 'W' && t[lt - 1] == 'S')
        t += 'W';
    else if (s == 'x' && t[lt - 2] == 'W' && t[lt - 1] == 'S')
        t += 'S';
    else if (s == 'o' && t[lt - 2] == 'S' && t[lt - 1] == 'W')
        t += 'W';
    else if (s == 'x' && t[lt - 2] == 'S' && t[lt - 1] == 'W')
        t += 'S';
    else if (s == 'o' && t[lt - 2] == 'W' && t[lt - 1] == 'W')
        t += 'S';
    else if (s == 'x' && t[lt - 2] == 'W' && t[lt - 1] == 'W')
        t += 'W';
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n;
    string s;
    cin >> n >> s;
    string ans = "None";
    s = s + s;

    string t1, t2, t3, t4;
    t1 = "SS", t2 = "WS", t3 = "SW", t4 = "WW";

    rep(i, 2 * n - 2)
    {
        add_animal(s[i + 1], t1);
        add_animal(s[i + 1], t2);
        add_animal(s[i + 1], t3);
        add_animal(s[i + 1], t4);
    }

    if (t1.substr(0, n) == t1.substr(n, 2*n))
        ans = t1.substr(0, n);
    if (t2.substr(0, n) == t2.substr(n, 2*n))
        ans = t2.substr(0, n);
    if (t3.substr(0, n) == t3.substr(n, 2*n))
        ans = t3.substr(0, n);
    if (t4.substr(0, n) == t4.substr(n, 2*n))
        ans = t4.substr(0, n);

    if (ans == "None")
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}