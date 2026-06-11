#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int n = s.size();
    long long res = 0;
    
    for(int bit = 0; bit < 1 << (n - 1); ++bit)
    {
        long long tmp = 0;
        
        // move to next digit by multiplying 10
        for(int j = 0; j < n - 1; ++j)
        {
            tmp *= 10;
            tmp += s[j] - '0';
            
            // insert plus sign
            if(bit & (1 << j))
            {
                res += tmp;
                tmp = 0;
            }
        }
        // add tmp to result at the last digit
        tmp *= 10;
        tmp += s.back() - '0';
        res += tmp;
    }
    
    cout << res << "\n";
    return 0;
}