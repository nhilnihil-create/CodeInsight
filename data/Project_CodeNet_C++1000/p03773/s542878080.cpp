#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    cin >> A >> B;

    cout << (A + B) % 24 << '\n';

    return 0;
}