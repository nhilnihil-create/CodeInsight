#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int h, w;
    string word;
    string dot = "#";
    cin >> h >> w;
    vector<string> a(h);

    for (int i = 0; i < h; i++) {
        cin >> a.at(i);
    }

    // 1行目はすべて#になる
    for (int i = 0; i < w; i++) {
        word += dot;
    }
    cout << dot << word << dot << endl;
    
    for (int i = 0; i < h; i++) {
        cout << dot << a.at(i) << dot << endl;
    }

    // 最終行もすべて#になる
    cout << dot << word << dot << endl;    
    
}