#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N,M;
    cin >> N >> M;

    ll count = 0;

    if(N * 2 <= M)
    {
        M -= N * 2;
        count += N;
        count += M / 4;
    }
    else
    {
        count = M / 2;
    }

    cout << count << endl;
    
    return 0;
}