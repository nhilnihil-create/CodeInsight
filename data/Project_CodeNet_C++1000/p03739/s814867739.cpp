#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    ll sum = 0;
    // flag = 1なら正にしたい
    int flag = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
       sum += a[i];
       if (sum == 0)
       {
           ans += (ll)1;
           if (flag)
               sum = 1;
           else
               sum = -1;
       }
       else if ((flag==1) ^ (sum > 0) == 1)
       {
           ans += (ll)(abs(sum)+1);
           if (flag)
               sum = 1;
           else
               sum = -1;
       }
       flag = (flag+1)%2;
    }
    sum = 0;
    flag = 0;
    ll temp = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if(sum == 0)
        {
            temp += (ll)1;
            if (flag)
                sum = 1;
            else
                sum = -1;
        }
        else if ((flag == 1) ^ (sum > 0) == 1)
        {
            temp += (ll)(abs(sum) + 1);
            if (flag)sum = 1;
            else sum = -1;
        }
        flag = (flag + 1) % 2;
    }
    cout << min(temp, ans) << endl;
}