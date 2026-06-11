#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    string A; cin >> A;
    vector<int> B { A.size() };
    int letters = 0;
    for (int i = A.size()-1; i >= 0; i--) {
        letters |= 1 << (A[i] - 'a');
        if (letters == (1 << 26)-1) {
            B.push_back(i);
            letters = 0;
        }
    }
    int pos = 0;
    while (!B.empty()) {
        int letters = 0;
        for (int i = pos; i < B.back(); i++) {
            letters |= 1 << (A[i] - 'a');
        }
        char ch = 0;
        for (int i = 0; i < 26; i++) {
            if (!(letters & (1 << i))) {
                ch = 'a' + i;
                break;
            }
        }
        cout << ch;
        while (pos < A.size() && A[pos] != ch) pos++;
        pos++;
        B.pop_back();
    }
    cout << '\n';
    return 0;
}
