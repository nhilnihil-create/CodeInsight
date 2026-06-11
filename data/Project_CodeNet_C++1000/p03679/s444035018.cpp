#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll X, A, B;
        cin >> X >> A >> B;

        if (A >= B) {
                cout << "delicious" << endl;
        }
        else if (B -A > X) {
                cout << "dangerous" << endl;
        }
        else {
                cout << "safe" << endl;
        }


}
