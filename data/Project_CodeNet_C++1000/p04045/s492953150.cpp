#include <iostream>
using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    bool dislikes[10] = {false};
    for (int i = 0, x; i < k; i++)
    {
        cin >> x;
        dislikes[x] = true;
    }

    auto valid = [&](int x) {
        while (x)
        {
            int d = x % 10;
            if (dislikes[d])
                return false;
            x /= 10;
        }
        return true;
    };

    for (int p = n; p < 100001; p++)
        if (valid(p))
        {
            cout << p << endl;
            break;
        }
}
