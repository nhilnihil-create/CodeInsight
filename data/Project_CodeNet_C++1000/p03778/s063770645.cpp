#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define pw(x) (1LL << (x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, a, b;
    cin >> w >> a >> b;

    int a_min = a, a_max = a + w;
    int b_min = b, b_max = b + w;

    if ((b_min >= a_min && b_min <= a_max) || (b_max >= a_min && b_max <= a_max))
        cout << 0 << '\n';
    else if (a_max < b_min)
        cout << b_min - a_max << '\n';
    else if (b_max < a_min)
        cout << a_min - b_max << '\n';

    return 0;
}