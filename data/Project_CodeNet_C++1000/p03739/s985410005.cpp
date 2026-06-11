#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<signed long long> a(n);
    for (long long i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    long long even = 0;
    long long odd = 0;
    long long sum = 0;
    for (long long i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            if (sum + a[i] > 0)
            {
                sum += a[i];
            }
            else
            {
                even += abs(sum + a[i] - 1);
                sum = 1;
            }
        }
        else
        {
            if (sum + a[i] < 0)
            {
                sum += a[i];
            }
            else
            {
                even += sum + a[i] + 1;
                sum = -1;
            }
        }
    }
    sum = 0;
    for (long long i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            if (sum + a[i] < 0)
            {
                sum += a[i];
            }
            else
            {
                odd += sum + a[i] + 1;
                sum = -1;
            }
        }
        else
        {
            if (sum + a[i] > 0)
            {
                sum += a[i];
            }
            else
            {
                odd += abs(sum + a[i] - 1);
                sum = 1;
            }
        }
    }
    cout << min(even, odd) << endl;
}