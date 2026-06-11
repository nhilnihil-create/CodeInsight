#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    double density = 0.0;
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; 100 * a * i <= f; ++i)
    {
        for (int j = 0; 100 * (a * i + b * j) <= f; ++j)
        {
            int water = 100 * (a * i + b * j);
            for (int k = 0; water + k * c <= f; ++k)
            {
                for (int l = 0; water + k * c + l * d <= f; ++l)
                {
                    int sugar = k * c + l * d;
                    if (sugar <= e * water / 100)
                    {
                        if (double(100 * sugar) / double(water + sugar) >= density)
                        {
                            density = max(density, double(100 * sugar) / double(water + sugar));
                            ans1 = water + sugar;
                            ans2 = sugar;
                        }
                    }
                }
            }
        }
    }
    cout << ans1 << " ";
    cout << ans2 << endl;
}