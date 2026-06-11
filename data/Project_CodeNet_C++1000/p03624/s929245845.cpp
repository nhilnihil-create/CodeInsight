#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    string S;
    cin >> S;
    map<char, int> list;
    for (int i = 0; i < S.size(); i++)
        list[S[i]]++;
    bool x = true;
    for (auto y = 'a'; y <= 'z'; y++)
        if (list.find(y) == list.end())
        {
            cout << y;
            x = false;
            break;
        }
    if (x)
        cout << "None";
}
