#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int W,a,b;
    int move;

    cin >> W >> a >> b;

    move = (a > b) ? a-(b+W):b-(a+W);
    if(move < 0)move = 0;

    cout << move << "\n";

    return 0;
}
