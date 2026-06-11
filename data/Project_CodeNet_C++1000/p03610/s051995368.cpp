#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;


    int i = 0;
    int N = s.size();
    while (2 * i < N) {
        cout << s.at(2 * i);
        i++;
    }
    cout << endl;
}
