#include <cstdio>

using namespace std;

int n;
int digits[3];

void solve()
{
    for (int i = 0; i < 3; i++) {
        digits[i] = n%10;
        n /= 10;
    }

    if (digits[0] == digits[2]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main()
{
    scanf("%d", &n);
    solve();
    return 0;
}