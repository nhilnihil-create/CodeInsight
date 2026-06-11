#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;

int main(void)
{
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n)
    {
        int x;
        cin >> x;
        if (i % 2 == 0)
        {
            a.insert(a.begin(), x);
        }
        else
        {
            a.push_back(x);
        }
    }
    if (n % 2 == 0)
    {
        reverse(a.begin(), a.end());
    }
    for (int e : a)
    {
        cout << e << " ";
    }
}
