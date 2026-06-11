#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int sx, tx, sy, ty;

    cin >> sx >> sy >> tx >> ty;

    int x, y;

    //①↑→最短
    x = abs(ty - sy);
    y = abs(tx - sx);
    for (int i = 0; i < x; i++) cout << "U";
    for (int i = 0; i < y; i++) cout << "R";

    //②↓←最短(①と同じ値)
    x = abs(ty - sy);
    y = abs(tx - sx);
    for (int i = 0; i < x; i++) cout << "D";
    for (int i = 0; i < y; i++) cout << "L";

    //③↑→ ①+1ずつ
    x = abs(ty - sy)+1;
    y = abs(tx - sx)+1;
    cout << "L";//+1分
    for (int i = 0; i < x; i++) cout << "U";
    for (int i = 0; i < y; i++) cout << "R";
    cout << "D";//+1分

    //④↑→ ②+1ずつ
    x = abs(ty - sy)+1;
    y = abs(tx - sx)+1;
    cout << "R";//+1分
    for (int i = 0; i < x; i++) cout << "D";
    for (int i = 0; i < y; i++) cout << "L";
    cout << "U";//+1分

    cout << endl;
    //
}
