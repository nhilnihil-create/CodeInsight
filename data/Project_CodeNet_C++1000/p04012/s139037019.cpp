#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int times[26] = {0};
    string w;
    cin >> w;
    for (int i = 0; i < w.length(); ++i) {
        times[w[i] - 'a']++;
    }
    bool result = true;
    for (int i = 0; i < 26; ++i) {
        if (times[i] % 2 == 1) {
            result = false;
        }
    }
    if (result == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
