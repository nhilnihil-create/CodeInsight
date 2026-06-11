#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a.at(i);

    set<int> s;
    rep(i, n)
    {
        if (s.find(a.at(i)) == s.end())
        {
            s.insert(a.at(i));
        }
        else
        {
            s.erase(a.at(i));
        }
    }

    cout << s.size() << endl;
    return 0;
}