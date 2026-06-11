#include <bits/stdc++.h>
using namespace std;

int main() {
    long H, W, h, w;
    cin >> H >> W >> h >> w;
    auto t = (H / h) * (W / w), k = H * W - (H / h) * (W / w) * h * w;
    if(k == 0)return 0 & puts("No");
    puts("Yes");
    auto c = 1 + t / k, l = c * (h * w - 1) + 1;
    for(unsigned long i = 1; i <= H; ++i){
        for(unsigned long j = 1; j <= W; ++j)cout << (i % h || j % w ? c : -l) << " ";
        cout << endl;
    }
    return 0;
}