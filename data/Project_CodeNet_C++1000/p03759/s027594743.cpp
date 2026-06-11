#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int a[3];
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    sort(a, a + 3);
    if (a[2] - a[1] == a[1] - a[0]) printf("YES");
    else printf("NO");
    return 0;
}