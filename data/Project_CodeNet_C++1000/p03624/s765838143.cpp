#include<iostream>
using namespace std;

int main() {
    string S; cin >> S;
    for (int i = 0; i < 26; i++) {
        bool ismatched = false;
        char alphabet = i + 'a';
        for (int j = 0; j < S.size(); j++) {
            if (S[j] == alphabet) {
                ismatched = true;
            }
        }
        if (!ismatched) {
            cout << alphabet << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}
