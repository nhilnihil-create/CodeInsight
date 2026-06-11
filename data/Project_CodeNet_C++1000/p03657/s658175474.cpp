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

    if (a%3 && b%3 && (a+b)%3) {
        cout << "Impossible" << endl;
    }
    else {
        cout << "Possible" << endl;
    }
}
