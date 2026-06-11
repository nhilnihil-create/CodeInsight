#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;

    long long K = N * 3;
    long long sol = 0;

    long long arr[K];

    for(long long k=0; k<K; k++)
    {
        cin >> arr[k];
    }

    sort(arr,arr+K);

    long long n = 0;

    for(long long k=(K-2); k>=0; k=k-2)
    {
        sol = sol + arr[k];
        n++;

        if(n == N)
        {
            break;
        }
    }

    cout << sol;
    return 0;
}

