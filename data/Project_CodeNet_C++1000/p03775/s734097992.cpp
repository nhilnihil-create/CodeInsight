#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long N;
    cin >> N;
    int ans = 0;
    int count = 0;
    for (int n = 1; n <= sqrt(N); ++n)
    {
        if (N % n == 0)
        {
            int B = N / n;
            for (int i = 0; i < 10; ++i)
            {
                B /= 10;
                if (B == 0)
                {
                    count = i + 1;
                    break;
                }
            }
            if (ans == 0)
            {
                ans = count;
            }
            else
            {
                ans = min(ans, count);
            }
        }
    }
    cout << ans << endl;
}