#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string S;
    cin >> S;
    set<char> characters;
    for (int i = 0; i < S.length(); i++) {
        characters.insert(S[i]);
    }
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++) {
        auto search = characters.find(alphabet[i]);
        if (search == characters.end()) {
            cout << alphabet[i] << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}
