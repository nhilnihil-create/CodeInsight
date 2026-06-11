#include <iostream>

int main()
{
    int n; std::cin >> n;
    int x[100100];
    for (int i = 0; i < n; i++) std::cin >> x[i];
    long long ans = 1;
    int prev = 1, j = 1;
    const int M = 1000000007;
    for (int i = 1; i < n; i++) {
        j++;
        if (prev + 1 == x[i]) { ans = ans * j % M; j--; }
        else {
            prev += 2;
        }
    }
    while (j > 0) ans = ans * j % M, j--;
    std::cout << ans << std::endl;
}
