#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int A, B, C, D; cin >> A >> B >> C >> D;
    if (min(B, D) - max(A, C) <= 0) printf("%d\n", 0);
    else printf("%d\n", min(B, D) - max(A, C));
}
