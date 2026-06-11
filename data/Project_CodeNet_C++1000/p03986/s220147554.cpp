#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    string s;
    cin >> s;
    stack<char> sta;
    repi(i, s.size(), 0)
    {
        if (!sta.empty())
        {
            if (sta.top() == 'S' && s[i] == 'T')
            {
                sta.pop();
            }
            else
            {
                sta.push(s[i]);
            }
        }
        else
        {
            sta.push(s[i]);
        }
    }
    cout << sta.size() << endl;
    return 0;
}