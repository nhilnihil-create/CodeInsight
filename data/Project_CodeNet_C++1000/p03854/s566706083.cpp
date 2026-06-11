#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    string dream = "dream";
    string dreamer = "dreamer";
    string erase = "erase";
    string eraser = "eraser";
    reverse(dream.begin(), dream.end());
    reverse(dreamer.begin(), dreamer.end());
    reverse(erase.begin(), erase.end());
    reverse(eraser.begin(), eraser.end());

    int i;
    for (i = 0; i < s.size(); i++) {
        if (dream == s.substr(i,5)) {
            i += 4;
            continue;
        }
        else if (dreamer == s.substr(i,7)) {
            i += 6;
            continue;
        }
        else if (erase == s.substr(i,5)) {
            i += 4;
            continue;
        }
        else if (eraser == s.substr(i,6)) {
            i += 5;
            continue;
        }
        else {
            break;
        }
    }

    if (i == s.size()) cout << "YES" << endl;
    else cout << "NO" << endl;
}