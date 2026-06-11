#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int W, a, b; cin >> W >> a >> b;
    if (abs(a - b) <= W) printf("%d\n", 0);
    else printf("%d\n", abs(a - b) - W);
}
