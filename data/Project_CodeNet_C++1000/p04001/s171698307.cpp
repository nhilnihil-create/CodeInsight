#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    long long res = 0;
    for(int bit = 0; bit < (1<<(n-1)); bit++)
    {
        long long tmp = 0;
        for(int i = n-2; i >= 0; i--)
        {
            tmp *= 10;
            tmp += s[n-2-i] - '0';
            if(bit&(1<<i))
            {
                res += tmp;
                tmp = 0;
            }
        }
        tmp *= 10;
        tmp += s.back() - '0';
        res += tmp;
    }
    cout << res << endl;
    return 0;
}