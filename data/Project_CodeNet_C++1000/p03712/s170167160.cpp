#include <iostream>
#include <vector>
using namespace std;

int main() {

    int H, W;
    cin >> H >> W;

    vector<string> line;

    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        line.push_back(s);
    }

    string bar;
    for (int i = 0; i < W + 2; i++) {
        bar += "#";
    }

    cout << bar << endl;

    for (int i = 0; i < H; i++) {
        string s;
        s = "#" + line.at(i) + "#";
        cout << s << endl;

    }

    cout << bar << endl;

}
