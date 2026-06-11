#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string A, B; cin >> A >> B;
    if (A == B) {
        printf("%s\n", "EQUAL");
        return 0;
    }
    else {
        if (A.length() > B.length()) {
            printf("%s\n", "GREATER");
            return 0;
        }
        else if (A.length() < B.length()) {
            printf("%s\n", "LESS");
            return 0;
        }
        else {
            if (A > B) {
                printf("%s\n", "GREATER");
                return 0;
            }
            else if (A < B) {
                printf("%s\n", "LESS");
                return 0;
            }
        }
    }
}
