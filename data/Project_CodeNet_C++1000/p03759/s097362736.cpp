#include <iostream>
using namespace std;
int main() {
    int a, b, c; cin >> a >> b >> c;
    if (b - a == c - b) printf("%s\n", "YES");
    else printf("%s\n", "NO");
}