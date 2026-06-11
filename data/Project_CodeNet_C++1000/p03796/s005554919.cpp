#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    long long mod = 1000000007;
    long long power = 1;

    cin >> N;
    for(int i=1; i<=N; i++)
    {
        power = (power * i)%mod;
    }
    cout << power << endl;
    return 0;
}