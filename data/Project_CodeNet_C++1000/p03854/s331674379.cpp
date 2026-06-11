#include <bits/stdc++.h>
using namespace std;
#include <math.h>

int main() {
    string s;
    cin >> s;
    string check;
    bool a = true;

    while (s.size() >= 8) {
        check = "";
        for (int i = 0; i < 8; i++) {
            check.push_back(s.at(i));
        }
        if (check == "dreamdre" || check == "dreamera" || check == "erasedre" || check == "eraseera") {
            s.erase(0, 5);
        }
        else if (check == "eraserdr" || check == "eraserer") {
            s.erase(0, 6);
        }
        else if (check == "dreamerd" || check == "dreamere") {
            s.erase(0, 7);
        }
        else {
            a = false;
            break;
        }
    }

    if (a == true && s.size() >= 5) {
        if (s != "dream" && s != "dreamer" && s != "erase" && s != "eraser") {
            a = false;
        }
    }
    if (a == true && s.size() < 4) {
        a = false;
    }

    if (a == true) {
        cout << "YES" << endl;
    }
    if (a == false) {
        cout << "NO" << endl;
    }
}