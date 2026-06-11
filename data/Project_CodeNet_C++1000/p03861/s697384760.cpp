#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll countDivisibles(ll A, ll B, ll M)
{
    if (A % M == 0)
        return (B / M) - (A / M) + 1;
    return (B / M) - (A / M);
}
int main()
{
    ll A , B , M ; cin>>A>>B>>M;
    cout << countDivisibles(A, B, M) << endl;

    return 0;
}
