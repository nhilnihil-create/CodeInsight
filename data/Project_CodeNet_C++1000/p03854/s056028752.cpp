#include <bits/stdc++.h>
using namespace std;

int main() {

    string S;
    cin >> S;

    vector<string> D ={ "dream", "dreamer", "erase", "eraser" };
    int index = S.size();

    bool ok = true;
    int word_size = 0;
    while (ok && index > 1) {
        ok = false;
        for (int i = 0; i <D.size(); i++) {
            word_size = D.at(i).size();

            if (index - word_size < 0) {
                continue;
            }
            
            if (S.substr(index - word_size, word_size) == D.at(i)) {
                ok = true;
                index -= word_size;
                break;
            }
        }
    }

    if (index == 0) {
        cout << "YES" <<endl;
    }
    else {
        cout << "NO" <<endl;
    }

    return 0;
}