#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int K;
    cin >> s >> K;
    const int L = s.length();
    for (auto& x : s) {
        x -= 'a';
    }

    int M = K;
    for (int i = 0; i < L - 1; ++i) {
        if (s[i] == 0) {
            continue;
        }
        int d = 26 - s[i];
        if (M >= d) {
            s[i] = 0;
            M -= d;
        }
    }

    s.back() = (s.back() + M % 26) % 26;
    for (auto& x : s) {
        x += 'a';
    }
    cout << s << endl;
}
