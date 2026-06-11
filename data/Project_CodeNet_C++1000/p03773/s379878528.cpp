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
    int a, b;

    cin >> a >> b;

    a += b;
    if (a >= 24) {
        a -= 24;
    }
    cout << a << endl;
}
