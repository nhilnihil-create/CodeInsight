#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map <int, int> m;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    string s;
    getline(cin, s);

    for(int i = 0; i < s.size(); i++)
    {
        m[s[i] - 'a']++;
    }

    for(auto it = m.begin(); it != m.end(); it++)
    {
        if(it -> second % 2 != 0)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";



    return 0;
}
