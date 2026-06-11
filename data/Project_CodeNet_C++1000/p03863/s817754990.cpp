#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int n = (int)s.size();

    // sでは同一の文字が隣合わず、両端は取れないので
    // abababacbab <- cとる
    // abababacabab <- cの両側どちらか　その後上と同じ
    // など。最終状態abababab...abababになるまで文字を減らせる。
    // 最初の文字と最後の文字が違うときは最終状態の長さは偶数、
    // 初期状態の長さが奇数なら奇数回、偶数なら偶数回減らせるかのどちらかしかない。
    // 最初と最後が違うときは逆

    if(s[0] == s[n-1]) {
        if(n & 1) cout << "Second";
        else cout << "First";
        cout << endl;
    } else {
        if(n & 1) cout << "First";
        else cout << "Second";
        cout << endl;
    }
    return 0;
}