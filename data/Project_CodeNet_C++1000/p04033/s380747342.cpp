#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    string ans;

    if (0 < a )
    {

        ans = "Positive";
    }
    else if (a <= b && b < 0)
    {
        if ((b - a + 1) % 2 == 0)
        {
            ans = "Positive";
        }
        else
        {
            ans = "Negative";
        }
    }
    else if (a <= 0 && 0 <= b){

        ans = "Zero";
    }

    cout << ans << endl;
}
