#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    long long int a, b; cin >> a >> b;
    if (a >= 1 && b >= 1) printf("%s\n", "Positive");
    else if (a <= 0 && b >= 0) printf("%s\n", "Zero");
    else {
        long long int c = abs(0 - a), d = abs(0 - b);
        if ((c + d - 1) % 2 == 0) printf("%s\n", "Positive");
        else printf("%s\n", "Negative");
    }
}
