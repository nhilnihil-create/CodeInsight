#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    int a, b, c, d; std::cin >> a >> b >> c >> d;

    int min = std::min({a, b, c, d});
    int max = std::max({a, b, c, d});

    int ans = 0;

    for(int i = min; i <= max; i++) {
        if(i >= a && i <= b && i >= c && i <= d) {
            ans ++;
        }
    }

    if(ans) ans --;
    
    std::cout << ans << std::endl;
}
