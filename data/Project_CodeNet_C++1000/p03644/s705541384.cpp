
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define SortAsc(c) std::sort(c.begin(), c.end())
#define SortDesc(c) std::sort(c.rbegin(), c.rend())
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int log2int(int n)
{
    int res = 0;
    while (n > 0)
    {
        res++;
        n /= 2;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    cout << int(pow(2, int(log2(n)))) << endl;
}