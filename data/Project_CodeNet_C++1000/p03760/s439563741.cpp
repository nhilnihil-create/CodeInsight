#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    string O, E;
    cin >> O >> E;
    for (int i = 0; i < min(O.size(), E.size()); i++)
        cout << O[i] << E[i];
    if (O.size() > E.size())
        cout << O[O.size() - 1];
    if (O.size() < E.size())
        cout << E[E.size() - 1];
}