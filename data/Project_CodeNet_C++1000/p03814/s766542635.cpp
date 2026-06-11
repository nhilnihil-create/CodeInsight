#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int front_a = s.size(), back_z = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') front_a = min(front_a, i);
        if (s[i] == 'Z') back_z = max(back_z, i);
    }
    cout << back_z - front_a + 1 << endl;
    return 0;
}