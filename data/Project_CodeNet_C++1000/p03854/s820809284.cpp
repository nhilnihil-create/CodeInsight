#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    bool x = true;
    while (S.size() != 0)
    {
        if (S.size() >= 5 && S.substr(0, 5) == "maerd")
            S.erase(0, 5);
        else if (S.size() >= 7 && S.substr(0, 7) == "remaerd")
            S.erase(0, 7);
        else if (S.size() >= 5 && S.substr(0, 5) == "esare")
            S.erase(0, 5);
        else if (S.size() >= 6 && S.substr(0, 6) == "resare")
            S.erase(0, 6);
        else
        {
            x = false;
            break;
        } 
    }
    cout << (x ? "YES" : "NO");
}