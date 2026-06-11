#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    string s;
    cin >> s;
    for (int i = s.size() - 2; i >= 2; i -= 2) {
        if (s.substr(0, i / 2) == s.substr(i / 2, i / 2)) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
