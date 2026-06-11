#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T, A;
    string s, a_string;

    cin >> s;

    for (int i = 0; i < s.length(); i += 2){
        a_string = a_string + s[i];
    }

    cout << a_string << endl;
}