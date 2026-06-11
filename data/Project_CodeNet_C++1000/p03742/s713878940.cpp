#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int n;
long long X, Y;
int mod = 1e9 + 7;

int main() {
    cin >> X >> Y;
    cout << (max(X, Y) - min(X, Y) > 1? "Alice": "Brown") << endl;
}
