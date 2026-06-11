#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    double border = 1.0 * E / (100 + E);
    double max = 0;
    int max_w = 0, max_s = 0;
    for (int a = 0; a <= F / (A * 100); a++)
    {
        for (int b = 0; b <= (F - (a * A * 100)) / (B * 100); b++)
        {
            for (int c = 0; c <= (F - (a * A * 100) - (b * B * 100)) / C; c++)
            {
                for (int d = 0; d <= (F - (a * A * 100) - (b * B * 100) - (c * C)) / D; d++)
                {
                    int water = (a * A * 100) + (b * B * 100);
                    int suger = (c * C) + (d * D);
                    double node = (1.0 * suger) / (water + suger);
                    if (node <= border)
                    {
                        if (node >= max)
                        {
                            max = node;
                            max_w = water;
                            max_s = suger;
                        }
                    }
                }
            }
        }
    }
    cout << max_w + max_s << ' ' << max_s << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
