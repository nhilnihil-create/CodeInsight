#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N; cin >> N;

        ll tmp = N / 10.0;
        ll tmp2 = N - (tmp * 10);
        if (tmp == 9 || tmp2 == 9) {
                cout << "Yes" << endl;
        }
        else cout << "No" << endl;


}
