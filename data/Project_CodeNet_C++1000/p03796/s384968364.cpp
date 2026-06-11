#include <bits/stdc++.h>
using namespace std;


int main()
{
    int64_t N;
    cin >> N;
    int64_t chk=1000000007;
    int64_t ans=1;
    while(N>0)
    {
        ans=ans*N;
        ans=ans%chk;
        N--;
    }
    cout << ans << endl;
}