#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>  // memset()
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define For(i, a, b) for (int i = (int)(a), sz = (int)(b); i < sz; i++)
#define rFor(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fill(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0), cin.tie(0)

const int MAX = 1e2 + 1;

int main() {
    IO;
    int a, b;
    cin >> a >> b;
    printf("%d\n", (a + b) % 24);
    return 0;
}