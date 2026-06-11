#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class T>
T gcd(T x, T y)
{
    if (x < y)
    {
        std::swap(x, y); //小さい方をyとする
    }
    int r = x % y;
    while( r != 0 )
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int g = gcd(a, b);
    if (c % g == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    return 0;
}
