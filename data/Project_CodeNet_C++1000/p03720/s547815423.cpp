#include <iostream>

int main () {
    int n, m, a, b;
    std::cin >> n >> m;
    int ans[60]={0};
    for(int i = 0; i < m; ++i){
        std::cin >> a >> b;
        ++ans[a];
        ++ans[b];
    }
    for(int i = 1; i <= n; ++i){
        std::cout << ans[i] << std::endl;
    }
}