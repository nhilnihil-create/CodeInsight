
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

void Main() {
    // input
    string s;
    cin >> s;


    // translate
    reverse(s.begin(), s.end());
    string divide[4] = {"dream", "dreamer", "erase", "eraser"};
    for (int i = 0; i < 4; i++) {
        reverse(divide[i].begin(), divide[i].end());
    }

    bool isDeivided = false;
    for (int i = 0; i < s.length();) {
        isDeivided = false;
        for (int j = 0; j < 4; j++) {
            if (s.substr(i, divide[j].length()) == divide[j]) {
                i += divide[j].length();
                isDeivided = true;
                break;
            }
        }
        if (isDeivided) {
            continue;
        }
        
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    // output

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
