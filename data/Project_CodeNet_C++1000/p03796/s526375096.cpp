#include <iostream>
using namespace std;

int main()
{
    long long n, sum=1;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        sum*=i;
        sum%=1000000007;
    }
    cout << sum;
}
