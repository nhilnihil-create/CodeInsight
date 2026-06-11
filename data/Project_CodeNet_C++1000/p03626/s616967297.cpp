#include <iostream>

using namespace std;

const u_int64_t R = 1'000'000'007LL;
u_int64_t way[52];

int main()
{
    int N;
    string s1, s2;

    cin >> N >> s1 >> s2;

    for (int i = 0; i < N; i++)
    {
        char c01 = s1[i];
        char c11 = s2[i];
        if (i == 0)
        {
            if (c01 == c11)
            {
                // |
                way[i] = 3;
            }
            else
            {
                // =
                way[i] = 6;
            }
            continue;
        }

        char c00 = s1[i - 1];
        char c10 = s2[i - 1];

        if (c00 == c01)
        {
            // =
            way[i] = way[i - 1];
            continue;
        }

        if (c00 == c10)
        {
            if (c01 == c11)
            {
                // ||
                way[i] = 2LL * way[i - 1] % R;
            }
            else
            {
                // |=
                way[i] = 2LL * way[i - 1] % R;
            }
        }
        else
        {
            if (c01 == c11)
            {
                // =|
                way[i] = way[i - 1];
            }
            else
            {
                // ==
                way[i] = 3LL * way[i - 1] % R;
            }
        }
    }

    cout << way[N - 1] << endl;

    return 0;
}