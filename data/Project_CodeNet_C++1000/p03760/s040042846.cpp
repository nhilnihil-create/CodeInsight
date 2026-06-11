#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    string O, E;
    cin >> O >> E;
    int n;

    rep(i, E.length())
    {
        cout << O[i] << E[i];
    }
    if (O.length() > E.length())
    {
        cout << O[O.length() - 1];
    }
    cout << endl;
    return 0;
}
