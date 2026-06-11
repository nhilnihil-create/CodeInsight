#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll N, i,ans, l[50], K;
int main()
{
    cin >> N >> K;
    for(i=0;i<N;i++)
    {
        cin >> l[i];
    }
    sort(l, l+N);
    for(i=N-1;i>N-K-1;i--)
    {
        ans += l[i];
    }
    cout << ans << endl;
}
