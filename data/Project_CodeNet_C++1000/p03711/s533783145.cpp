#include <iostream>
using namespace std;

using Int = long long int;
using UInt = unsigned long long int;


int main(void) {
    int x, y;
    cin >> x >> y;
    int g_num[13] = {0,1,3,1,2,1,2,1,1,2,1,2,1};
    if (g_num[x] == g_num[y]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
