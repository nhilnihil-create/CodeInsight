#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll A, B;
        cin >> A >> B;
        if (A % 3 == 0 || B % 3 == 0 || (A+B) % 3 == 0) {
                cout << "Possible" << endl;
        }
        else cout << "Impossible" << endl;


}
