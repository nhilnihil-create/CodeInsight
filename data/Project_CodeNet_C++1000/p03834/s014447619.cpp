#include <bits/stdc++.h>
#include <regex>
#define ll long long int
#define yorn(f) cout << ((f) ? "Yes" : "No") << endl
#define YORN(f) cout << ((f) ? "YES" : "NO") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

string replace(string s, string x, string y) {
    string::size_type pos = 0;
    while ((pos = s.find(x, pos)) != std::string::npos)
    {
        s.replace(pos, x.size(), y);
        pos += y.size();
    }
    return s;
}

int main()
{
    string s;
    cin >> s;

    cout << replace(s, ",", " ") << endl;

    return 0;
}