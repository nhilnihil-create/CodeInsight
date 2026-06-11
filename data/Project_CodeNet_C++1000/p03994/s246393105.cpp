#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    string s;
    int k;
    cin >> s >> k;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] != 'a' && k >= (26 - (s[i] - 'a')))
        {
            k -= 26 - (s[i] - 'a');
            s[i] = 'a';
        }
    }
    k %= 26;
    s[s.size() - 1] = (s[s.size() - 1] - 'a' + k) % 26 + 'a';
    cout << s << "\n";

    return 0;
}