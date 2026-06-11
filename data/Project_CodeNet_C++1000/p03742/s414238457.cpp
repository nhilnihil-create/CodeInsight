#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll X,Y;
    cin >> X >> Y;
    cout << (llabs(X-Y)<=1 ? "Brown" : "Alice") << endl;

    return 0;
}