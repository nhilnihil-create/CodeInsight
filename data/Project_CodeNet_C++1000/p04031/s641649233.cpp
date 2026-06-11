#include <iostream>
#include <vector>
static int c(std::vector<int> &a, int s)
{
    int ss = 0;
    for (const auto aa: a)
    {
        ss += (s - aa) * (s - aa);
    }
    return ss;
}
int main()
{
    int n; std::cin >> n;
    std::vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        s += a[i];
    }

    s /= n;

    std::cout << std::min(c(a, s), c(a, s+1)) << std::endl;

    return 0;
}
