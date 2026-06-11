#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    int size = S.size();
    bitset<10> b;
    long long sum = 0;
    int pos;
    string former;
    for (int tmp = 0; tmp < (1 << size - 1); tmp++) {
        b = tmp;
        former = S;
        for (int i = 0; i < size - 1; i++) {
            if (b.test(i)) {
                pos = size - i - 1;
                sum += stoll(former.substr(pos, former.size() - pos));
                former = former.substr(0, pos);
            }
        }
        if (former.size() != 0) {
            sum += stoll(former);
        }
    }
    cout << sum << endl;
}
