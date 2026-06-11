#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int pos = 0;
    while(pos < n && s[pos] == 'T') pos++;
    int ans = pos;
    int snum = 0;
    while(pos < n)
    {
        if(pos < n && s[pos] == 'S')
        {
            pos++;
            snum++;
        }
        if(pos == n) break;
        int tnum = 0;
        while(pos < n && s[pos] == 'T')
        {
            pos++;
            tnum++;
        }
        if(tnum >= snum)
        {
            tnum -= snum;
            ans += tnum;
            snum = 0;
        }
        else
        {
            snum -= tnum;
        }
    }
    cout << ans + snum << endl;
}
