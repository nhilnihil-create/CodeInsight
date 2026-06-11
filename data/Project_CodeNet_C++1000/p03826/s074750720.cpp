#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
// #include <cmath>
// #include <string>

using namespace std;
// typedef unsigned long long ull;


int main(int argc, char const *argv[]) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << max(A * B, C * D) << endl;
    return 0;
}
