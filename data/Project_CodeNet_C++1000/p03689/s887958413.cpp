#include <bits/stdc++.h>

int main() {
    long long H, W, h, w;
    std::cin >> H >> W >> h >> w;
    if (H % h == 0 && W % w == 0) {
        std::cout << "No" << std::endl;
        return 0;
    }

    std::cout << "Yes" << std::endl;
    if (W % w) {
        std::vector<long long> s(W + 1);
        s[W] = 1;
        s[W - W % w] = - W / w;
        for (auto i = W - w; i > 0; i--) s[i] = i % w ? s[i + w] + 1 : - i / w;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) std::cout << s[j + 1] - s[j] << " ";
            std::cout << std::endl;
        }
    } else {
        std::vector<long long> s(H + 1);
        s[H] = 1;
        s[H - H % h] = - H / h;
        for (auto i = H - h; i > 0; i--) s[i] = i % h ? s[i + h] + 1 : - i / h;
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) std::cout << s[i + 1] - s[i] << " ";
            std::cout << std::endl;
        }
    }

    return 0;
}