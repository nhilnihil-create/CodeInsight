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
    string target = "CODEFESTIVAL2016";

    int count = 0;
    for (int i = 0; i < target.size(); i++)
    {
        count += (target[i] != s[i]);
    }
    cout << count << endl;
}
