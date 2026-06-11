#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6;

typedef long long ll;

ll a[N],b[N];

int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n ; i ++ )
        {
            cin >> a[i];
            sum += a[i];
            b[i] = b[i-1] + a[i];
        }

    ll minn = 1e10;

    for (int i = 1; i < n ; i ++ )
    {
        if(minn >= abs(2*b[i]-sum)) minn = abs(2*b[i]-sum);
    }
    cout << minn << endl;

    return 0;
}
