#include <iostream>
using namespace std;

int main() {
    long long a, b; cin >> a >> b;
    if (a * b <= 0) { puts("Zero"); return 0; }
    else if (a > 0 && b > 0) { puts("Positive"); return 0; }
    else { 
        if ((b - a + 1) % 2) puts("Negative");
        else puts("Positive");
    }
}