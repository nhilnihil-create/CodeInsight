#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

const int R = 700;
int n, q, L;
int x[500000];
int go1[500000];
int goroot[500000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cin >> L;
    int i = 0, j = 0;
    for (; i < n; i++)
    {
        while (j + 1 < n && x[j + 1] - x[i] <= L)
        {
            j++;
        }
        go1[i] = j;
    }
    for (int i = 0; i < n; i++)
    {
        int g = go1[i];
        for (int j = 1; j < R; j++)
            g = go1[g];
        goroot[i] = g;
    }
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (b < a)
            swap(a, b);
        a--;
        b--;
        int d = 0;
        while (goroot[a] < b)
        {
            a = goroot[a];
            d += R;
        }
        while (a < b)
        {
            a = go1[a];
            d++;
        }
        cout << d << "\n";
    }
}
