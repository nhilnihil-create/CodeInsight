#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    string a, b;
    cin >> a >> b;
    if (a.size() < b.size())
    {
        cout << "LESS" << '\n';
    }
    else if (a.size() > b.size())
    {
        cout << "GREATER" << '\n';
    }
    else
    {
        cout << ((a < b) ? "LESS" : (a == b) ? "EQUAL" : "GREATER") << '\n';
    }
    return 0;
}
