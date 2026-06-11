#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long

int main() {
    string a, b;
    cin >> a;
    b = a;
    reverse(a.begin(), a.end());
    if(a == b) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}