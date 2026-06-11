#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    ll countEven = 0, countOdd = 0;
    REP(i, N)
    {
        ll a;
        cin >> a;
        if (a % 2 == 0)
        {
            countEven++;
        }
        else
        {
            countOdd++;
        }
    }
    
    string ans;
    if (countOdd % 2 == 0)
    {
        ans = "YES";
    }
    else
    {
        ans = "NO";
    }
    

    cout << ans << endl;
}
