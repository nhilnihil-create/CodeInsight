#include <iostream>
#include <string>
using namespace std;

void add_dir(string& way, char dir, int num) {
    for (int i = 0; i < num; i++) {
        way.push_back(dir);
    }
}

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    string way = "";
    add_dir(way, 'U', ty - sy);
    add_dir(way, 'R', tx - sx);
    add_dir(way, 'D', ty - sy);
    add_dir(way, 'L', tx - sx);
    add_dir(way, 'L', 1);
    add_dir(way, 'U', ty - sy + 1);
    add_dir(way, 'R', tx - sx + 1);
    add_dir(way, 'D', 1);
    add_dir(way, 'R', 1);
    add_dir(way, 'D', ty - sy + 1);
    add_dir(way, 'L', tx - sx + 1);
    add_dir(way, 'U', 1);

    cout << way << endl;
    return 0;
}