#include <bits/stdc++.h>
using namespace std;

int A, B, C, D, E, F;

int main()
{
    cin >> A >> B >> C >> D >> E >> F;

    double ma = 0.0;
    int maall = 0, mas = 0;

    double limit = (double)100.0 * E / (100.0 + E);

    for (int a1 = 0; 100 * A * a1 <= F; a1++)
    {
        for (int a2 = 0; 100 * A * a1 + 100 * B * a2 <= F; a2++)
        {
            if (A * a1 + B * a2 == 0)
                continue;

            for (int a3 = 0; 100 * A * a1 + 100 * B * a2 + C * a3 <= F; a3++)
            {
                for (int a4 = 0; 100 * A * a1 + 100 * B * a2 + C * a3 + D * a4 <= F; a4++)
                {
                    double c = (double)100 * (C * a3 + D * a4) / (double)(100 * A * a1 + 100 * B * a2 + C * a3 + D * a4);

                    if (c <= limit)
                    {
                        if (c >= ma)
                        {
                            ma = c;
                            maall = 100 * A * a1 + 100 * B * a2 + C * a3 + D * a4;
                            mas = C * a3 + D * a4;
                        }
                    }
                }
            }
        }
    }

    cout << maall << " " << mas << endl;

    return 0;
}
