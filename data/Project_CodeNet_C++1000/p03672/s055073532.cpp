#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    string str;
    cin >> str;
    size_t n = str.size();
    for (int i = 1; i < n - 1; ++i)
    {
        string sub = str.substr(0, n - i);
        size_t m = sub.size();
        if (m % 2 == 1) continue;
        string subleft = sub.substr(0, m / 2);
        string subright = sub.substr(m / 2, m / 2);
        if (subleft == subright)
        {
            cout << m << endl;
            return 0;
        }
    }
    return 0;
}
