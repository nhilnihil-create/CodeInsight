#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (int i = 0; i < s.size(); i++)
    {
        const int iter = ('z' - s[i] + 1) % 26;
        if (iter <= k)
        {
            k -= iter;
            s[i] = 'a';
        }
    }
    k %= 26;
    s.back() = static_cast<char>((s.back() - 'a' + k) % 26 + 'a');

    cout << s << endl;
}
