#include <iostream>
#include <string>
using namespace std;

using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    string a, b, c;
    cin >> a >> b >> c;
    int diff = 'A' - 'a';
    string res = "";
    res += (a[0] + diff); 
    res += (b[0] + diff); 
    res += (c[0] + diff); 
    cout << res << endl;
    return 0;
}
