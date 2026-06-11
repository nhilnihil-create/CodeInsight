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
    int num[3];

    cin >> num[0] >> num[1] >> num[2];

    sort(num, num+3);

    if (num[2] == num[0]+num[1]) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
