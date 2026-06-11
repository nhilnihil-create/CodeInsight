// 区間DPだな
// ICPC予選のだるま落としっていう問題に似ている、、
// でも Xの長さが200000だから、二次元配列は持てない
// "S...ST...T"になっている部分を探して、その長さを引けばよさそう、
// いや、"S S...ST...TS...ST...T T"の部分もまとめて落とせるし、
// ちょっとムズイですね、
#include <bits/stdc++.h>
using namespace std;

int main() {
    string X;
    cin >> X;
    stack<char> res;
    for (char ch : X) {
        if (res.size() == 0) {
            res.push(ch);
            continue;
        }

        if (ch == 'S') {
            res.push(ch);
        } else {
            if (res.top() == 'S') {
                res.pop();
            } else {
                res.push(ch);
            }
        }
    }
    cout << res.size() << endl;
    return 0;
}