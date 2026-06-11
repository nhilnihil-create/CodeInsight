#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll A[100010];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)cin >> A[i];

    ll ans = A[0] - 1;
    int mem = 2;
    for(int i = 1; i < N; i++)
    {
        if(A[i] < mem)continue;
        if(A[i] == mem)mem++;
        else ans += (A[i] - 1) / mem;
    }

    cout << ans << endl;
    return 0;
}
