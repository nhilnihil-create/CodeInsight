#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x;
    cin >> x;
    int len = x.size();

    int s = 0,ans = 0;
    for (int i = 0; i < len; i++)
    {
        if(x[i] == 'S')s++;
        else
        {
            if(s > 0)
            {
                s--;
            }
            else
            {
                ans++;
            }
        }
    }
    
    cout << ans + s << endl;
}