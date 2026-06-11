#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> A(3, 0);
    for (int i = 0; i < 3; i++) cin >> A[i];
    sort(A.begin(), A.end());
    printf("%d\n", A[0] + A[1]);
}