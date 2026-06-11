#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, x, sum;
    sum = 0;
    cin >> N >> K;
  
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if ((x * x) <= ((x - K) * (x - K)))
        {
            sum += 2 * x;
        }
        else if (x - K > 0)
        {
            sum += 2 * (x - K);
        }
        else
        {
            sum += 2 * (K - x);
        }
    }
    cout << sum << endl;
}
