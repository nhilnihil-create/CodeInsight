#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i, N, T[110], ans, g;
int main()
{
    cin >> N;
    for(i=0;i<N;i++)
        cin >> T[i];
    ans = T[0];
    for(i=1;i<N;i++)
    {
        g = __gcd(ans,T[i]);
        ans = (ans/g)*T[i];

    }
    cout << ans << endl;
}
