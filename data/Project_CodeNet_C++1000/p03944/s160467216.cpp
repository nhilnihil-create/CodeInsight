#include <iostream>

int main () {
    int w, h, n, x, y, a;
    std::cin >> w >> h >> n;
    int s[110][110] = {0};
    for(int i = 0; i < n; ++i){
        std::cin >> x >> y >> a;
        if(a == 1){
            for(int j = 0; j < x; ++j){
                for(int k = 0; k < h; ++k){
                    s[j][k] = 1;
                }
            }
        }
        if(a == 2){
            for(int j = x; j < w; ++j){
                for(int k = 0; k < h; ++k){
                    s[j][k] = 1;
                }
            }
        }
        if(a == 3){
            for(int j = 0; j < y; ++j){
                for(int k = 0; k < w; ++k){
                    s[k][j] = 1;
                }
            }
        }
        if(a == 4){
            for(int j = y; j < h; ++j){
                for(int k = 0; k < w; ++k){
                    s[k][j] = 1;
                }
            }
        }
        
    }
    int ans = 0;
    for(int i = 0; i < w; ++i){
        for(int j = 0; j < h; ++j){
            if(s[i][j] == 0) ++ ans;
        }
    }
    std::cout << ans << std::endl;
}