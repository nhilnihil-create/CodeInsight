#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n;
int u = 0, v = 0;
vector <int> A, B;
int main()
{
    cin >> n; n ++;
    for (int i = 0; (1ll << i) <= n; ++ i)
        if ((1ll << i) & n)
            u ++;
    for (int i = 0; (1ll << (i + 1)) <= n; ++ i)
    {
        if ((1ll << i) & n)
            B.push_back(++ v);
        A.push_back(u + i);
        B.push_back(u + i);
    }
    cout << A.size() + B.size() + u - 1 << endl;
    for (int i = 1; i < u; ++ i) cout << i << " ";
    for (int i = A.size() - 1; ~i; -- i) cout << A[i] << " ";
    for (int i = B.size() - 1; ~i; -- i) cout << B[i] << " ";
}
