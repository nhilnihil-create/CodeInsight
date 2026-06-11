
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#define INF 0x3f3f3f3f
#define inf 0x3f3f3f3f
#define MAX_N (1<<30)
#define eps 1e-5
#define ms(x, n) memset(x,n,sizeof(x));
using namespace std;
void optimize_cpp_stdio()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
}
typedef long long ll;

int main()
{
    ll x, y;
    scanf("%lld%lld", &x, &y);
    if(llabs(x - y) >= 2)
        printf("Alice\n");
    else
        printf("Brown\n");
    return 0;
}
