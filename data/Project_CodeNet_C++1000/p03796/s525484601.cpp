#include<bits/stdc++.h>
using namespace std;

int main()
{
    int64_t power=1;
    int64_t n;
    int64_t ref = 1000000007;

    cin >> n;

    for(int64_t i=1;i<=n;i++){
        power*=i;
        power%=ref;
    }
    cout << power <<endl;
}
