#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
        ll N, X;
        ll sum = 0;

        cin >> N >> X;
        
        sum += N;
        
        ll a, b;
        a = N - X, b = X;
        while ( b > 0 ) {
                ll q = a / b;
                sum += 2 * q * b;
                a -= q * b;
                swap(a, b);
        }

        cout << sum - a << endl;

        
        return ( 0 );
}
