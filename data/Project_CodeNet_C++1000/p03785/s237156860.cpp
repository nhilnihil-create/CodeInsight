#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, C, K;
    cin >> N >> C >> K;
    vector<ll> T(N);
    REP(i, N)
    {
        cin >> T[i];
    }
    sort(ALL(T));

    ll ans = 0;
    ll countNow = 0;
    ll timeLimitDeparture = 0;
    REP(i, N)
    {   
        if (countNow < C)
        {
            if (countNow == 0)
            {
                ans++;
                timeLimitDeparture = T[i] + K;
                countNow = 1;
            }
            else
            {
                if (timeLimitDeparture >= T[i])
                {
                    countNow++;
                }
                else
                {
                    ans++;
                    timeLimitDeparture = T[i] + K;
                    countNow = 1; 
                }
            }
            
        }
        else
        {
            ans++;
            timeLimitDeparture = T[i] + K;
            countNow = 1; 
        }
    }

    cout << ans << endl;
}
