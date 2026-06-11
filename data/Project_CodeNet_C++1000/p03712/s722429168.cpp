#include<bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> vec(H);
    for (int vi = 0; vi < H; vi++) {
        cin >> vec[vi];
    }
    string line = "";
    for (int x=0; x < W+2; x++) {
        line += "#";
    }
    cout << line << endl;
    for (int each = 0; each < H; each ++) {
        cout << "#" << vec[each] << "#" << endl;
    }
    cout << line << endl;
}