#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;

    bool flag = false;
    for(char ch = 'a'; ch <= 'z'; ch++) {
        for(int i = 0; i < S.size(); i++) {
            if(ch == S[i]) {
                flag = false;
                break;
            } 
            else {
                flag = true;
            }
        }
        if(flag) {
            cout << ch << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}