#include <math.h>
#include <iostream>
using namespace std;

int main()
{
    int i, j;
    bool dislike[10] = {false};

    int n, k;
    cin >> n >> k;

    int d;
    for (i = 0; i < k; i++)
    {
        cin >> d;
        dislike[d] = true;
    }

    int answer = n;
    int a;
    bool ok;
    while (true)
    {
        a = answer;
        ok = true;
        while (true)
        {
            if (dislike[a % 10])
            {
                ok = false;
                break;
            }
            if (a < 10)
            {
                break;
            }
            a /= 10;
        }
        if (ok)
        {
            break;
        }
        answer += 1;
    }
    cout << answer << endl;
}