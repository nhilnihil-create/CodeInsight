#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    int n;
    cin >> n;
    int c[9] = {0};
    repi(i, n, 0)
    {
        int a;
        cin >> a;
        if (a >= 3200)
        {
            c[8]++;
        }
        else if (a >= 2800)
        {
            c[7]++;
        }
        else if (a >= 2400)
        {
            c[6]++;
        }
        else if (a >= 2000)
        {
            c[5]++;
        }
        else if (a >= 1600)
        {
            c[4]++;
        }
        else if (a >= 1200)
        {
            c[3]++;
        }
        else if (a >= 800)
        {
            c[2]++;
        }
        else if (a >= 400)
        {
            c[1]++;
        }
        else
        {
            c[0]++;
        }
    }
    int ans = 0;
    repi(i,8,0){
        if(c[i] > 0)ans++;
    }
    cout << max(ans,1) << " " << ans + c[8]<< endl;
    return 0;
}