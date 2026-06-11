#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    string S;
    cin >> S;
    map<char, int> list;
    for (int i = 0; i < S.size(); i++)
        list[S[i]]++;
    if (list.size() == S.size())
        cout << "yes";
    else
        cout << "no";
}