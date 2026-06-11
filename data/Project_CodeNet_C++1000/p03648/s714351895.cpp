#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    long long k; cin >> k;
    long long a[50] = {};
    for (int i = 0; i < 50; i++) a[i] += 49 + k/50;
    for (int i = 0; i < 50; i++) a[i] += i < k%50 ? 51 - k%50 : -(k%50);
    cout << "50\n";
    for (int i = 0; i < 50; i++) cout << a[i] << ' ';
    cout << endl;
}