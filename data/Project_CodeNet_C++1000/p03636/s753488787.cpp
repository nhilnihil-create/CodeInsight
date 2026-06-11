#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << *s.begin() << s.size() - 2 << *s.rbegin() << endl;
    return 0;
}
