#include<iostream>
#include<string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    string S;
    cin >> H >> W;
    int a, b;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> S;
            if (S == "snuke") {
                a = j, b = i;
            }
        }
    }
    cout << char(a + 'A') << b + 1 << endl;
    return 0;
}