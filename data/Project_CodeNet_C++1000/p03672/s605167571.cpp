#include<iostream>
using namespace std;

int main() {
    string S; cin >> S;
    for (int i = S.size() - 2; i > 0; i -= 2) {
        string S_edited = S.substr(0, i);
        if (S_edited.substr(0, S_edited.size() / 2) == S_edited.substr(S_edited.size() / 2, S_edited.size() / 2)) {
            cout << S_edited.size() << endl;
            break;
        }
    }
}
