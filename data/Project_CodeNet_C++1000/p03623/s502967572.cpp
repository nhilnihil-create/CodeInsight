#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void YesNo(bool x) {
    cout << (x ? "Yes" : "No") << endl;
}

int main() {
    int x, a, b;
    cin >> x >> a >> b;
    if (abs(x - a) < abs(x - b))cout << "A" << endl;
    else cout << "B" << endl;
    return 0;
}