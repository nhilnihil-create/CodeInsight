#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long int sum = 0;
    for (int bit = 0; bit < (1 << (s.size() - 1)); bit++) {
        int last_ind = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (bit & (1 << s.size() - 2 - i)) {
                sum += stoll(s.substr(last_ind, i + 1 - last_ind));
                last_ind = i + 1;
            }
        }
        sum += stoll(s.substr(last_ind));
    }

    cout << sum << endl;
    return 0;
}