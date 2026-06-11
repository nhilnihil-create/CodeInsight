#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <string>
#include <cmath>

# define PI 3.14159265358979323846

using namespace std;

int main(void) {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int passed = 0;
    int bpassed = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == 'a') {
            if (passed < a + b) {
                cout << "Yes" << endl;
                passed++;
            } else {
                cout << "No" << endl;
            }
        } else if (s[i] == 'b') {
            if (passed < a + b && bpassed < b) {
                cout << "Yes" << endl;
                passed++;
                bpassed++;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
}