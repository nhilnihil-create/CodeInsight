#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;


    int i = 0;
    int N = s.size();
    string t;
    while (2 * i < N) {
        t += (s.at(2 * i));
        i++;
    }
    cout << t << endl;
}
