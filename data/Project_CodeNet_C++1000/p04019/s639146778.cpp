#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    string s;
    cin >> s;
    bool north = false;
    bool south = false;
    bool west = false;
    bool east = false;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'N') north = true;
        if(s[i] == 'S') south = true;
        if(s[i] == 'W') west = true;
        if(s[i] == 'E') east = true;
    }
    if(north != south || east != west) cout << "No" << endl;
    else cout << "Yes" << endl;
}
