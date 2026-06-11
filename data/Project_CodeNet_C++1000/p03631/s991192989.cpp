#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <iomanip>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string t(s);
    reverse(t.begin(), t.end());

    if (s == t) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
