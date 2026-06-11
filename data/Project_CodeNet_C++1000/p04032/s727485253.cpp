#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    for(int i=0; i<s.size()-1; i++)
        if(s[i]==s[i+1])
            return cout << i+1 << ' ' << i+2, 0;
    for(int i=0; i<s.size()-2; i++)
        if(s[i]==s[i+2])
            return cout << i+1 << ' ' << i+3, 0;

    cout << "-1 -1";
    return 0;
}
