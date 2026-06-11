#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int W, a, b;
    cin >> W >> a >> b;
    if(b > a+W) {
        cout << b-(a+W) << endl;
    } else if(b+W < a) {
        cout << a-(b+W) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}