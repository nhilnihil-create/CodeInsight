#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int enum_divisors(int N)
{
    vector<int> res;
    for (int i = 1; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i)
                res.push_back(N / i);
        }
    }
    return res.size();
}

int main(){
    int n;
    cin >> n;
    ll x(1);
    for(int i=1;i<=n;i++){
        x = (i*x) % 1000000007;
    }

    cout << x << endl;

    return 0;
}