#include <iostream>
#include <string>

using namespace std;

int main() {
    size_t n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    size_t num_qualifier = 0;
    size_t num_foreigner = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            if (num_qualifier < (a + b)) {
                cout << "Yes" << endl;
                ++num_qualifier;
            }
            else {
                cout << "No" << endl;
            }
        }
        else if (s[i] == 'b') {
            if (num_qualifier < (a + b) && num_foreigner < b) {
                cout << "Yes" << endl;
                ++num_qualifier;
                ++num_foreigner;
            }
            else {
                cout << "No" << endl;
            }
        }
        else {
            cout << "No" << endl;
        }
    }
    return EXIT_SUCCESS;
}