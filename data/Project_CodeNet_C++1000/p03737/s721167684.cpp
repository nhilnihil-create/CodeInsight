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
    string a, b, c;

    cin >> a >> b >> c;

    a[0] -= 0x20; b[0] -= 0x20; c[0] -= 0x20;

    cout << a[0] << b[0] << c[0] << endl;
}
