#include<bits/stdc++.h>
using namespace std;

int main()
{
    int64_t ans;
    int n, k;
    cin >>n >>k;

    ans = k;
    for(int i=1;i<=n-1;i++){
        ans*=k-1;
    }
    cout << ans << endl;
}