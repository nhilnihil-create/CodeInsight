#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define inf 1000000100

int main()
{
    int n;
    cin >> n;
    vi data;
    while(n--)
    {
        int a;
        cin >> a;
        data.pb(a);
    }
    ll sum1 = 0, sum2 = 0;
    ll ans1 = 0, ans2 = 0;
    for(int i = 0; i < data.size(); i++)
    {
        sum1 += data[i], sum2 += data[i];
        if(i%2 == 0)
        {
            if(sum1 <= 0)
            {
                ans1 += 1 - sum1;
                sum1 = 1;
            }
            if(sum2 >= 0)
            {
                ans2 += sum2 - (-1);
                sum2 = -1;
            }
        }
        else
        {
            if(sum1 >= 0)
            {
                ans1 += sum1 - (-1);
                sum1 = -1;
            }
            if(sum2 <= 0)
            {
                ans2 += 1 - sum2;
                sum2 = 1;
            }
        }
    }

    cout << min(ans1, ans2) << endl;
}
