#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string S;
    int ans = 0;

    cin >> S;

    for (int i = 0; i < 100; i++)
    {
        if (S[i + 2] != '\0')
        {
            ans++;
        }
        else
        {
            cout << S[0] << ans << S[i + 1] << endl;
            return 0;
        }
    }

    cout << S << endl;

    return 0;
}
