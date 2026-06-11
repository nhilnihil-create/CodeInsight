#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long int a,b;
    cin >> n >> a >> b;
    long long int x[n];
    for(int i = 0;i < n;i++)
    {
        cin >> x[i];
    }
    long long int sum = 0;
    for(int i = 1;i < n;i++)
    {
        sum += min(a * (x[i] - x[i - 1]),b);
    }
    cout << sum;

    return 0;
}