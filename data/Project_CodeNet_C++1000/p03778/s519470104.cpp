#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int W, a, b;
    cin >> W >> a >> b;
    if (a > b) swap(a, b);
    
    if (a + W > b) {
        cout << 0 << endl;
        return 0;
    }
    cout << b - (a + W) << endl;
    return 0;
}
