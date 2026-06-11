#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll city[N], tower[N];
int main()
{
#ifdef LOCAL
//    freopen("in.txt", "r", stdin);
#endif // LOCAL
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%s\n", abs(x-y)<=1?"Brown":"Alice");
    return 0;
}
