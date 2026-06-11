#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int minimum = min(B, D);
    int maxinum = max(A, C);
    if(minimum - maxinum > 0)
        cout << minimum - maxinum << endl;
    else
        cout << 0 << endl;
    return 0;
}