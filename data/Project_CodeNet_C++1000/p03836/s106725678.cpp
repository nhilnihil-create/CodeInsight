#include <iostream>
#include <string>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    string one = std::string(ty - sy, 'U') + std::string(tx - sx, 'R');
    string two = std::string(ty - sy, 'D') + std::string(tx - sx, 'L');
    cout << one + two + "LU" + one + "RD" + "RD" + two + "LU" << endl;
    return 0;
}
