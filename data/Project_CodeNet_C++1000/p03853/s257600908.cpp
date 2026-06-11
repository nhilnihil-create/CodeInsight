#include <bits/stdc++.h>
using namespace std;

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<char> c(w, 0);
    for (size_t i = 0; i < h; i++)
    {
        for (size_t j = 0; j < w; j++)
        {
            cin >> c[j];
            /* code */
        }
        for (size_t k = 0; k < 2; k++)
        {
            for (size_t l = 0; l < w; l++)
            {
                cout << c[l];
            }
            cout << endl;
        }
    }

    return 0;
}