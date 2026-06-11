#include <bits/stdc++.h>
using namespace std;

int N,K;

int main()
{
    cin>>N>>K;

    int ans;

    ans = K;
    ans *= pow(K-1,N-1);

    cout << ans << endl;
    return 0;
}
