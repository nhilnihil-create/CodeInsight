#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, A, B, a = 0, b = 0; string S; cin >> N >> A >> B >> S;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'a' && a < A + B) {
            printf("%s\n", "Yes");
            a++;
        }
        else if (S[i] == 'b' && b + 1 <= B && a < A + B) {
            printf("%s\n", "Yes");
            a++, b++;
        }
        else printf("%s\n", "No");
    }
}
