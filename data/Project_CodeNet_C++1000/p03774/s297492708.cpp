#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
    vector<pair<int, int>>v1;
    vector<pair<int, int>>v2;
    int m, n, n1, m1;
    cin>>n>>m;
    n1 = n;
    m1 = m;
    while(n1--)
    {
        int a, b;
        cin>>a>>b;
        v1.push_back(make_pair(a, b));
    }
    while(m1--)
    {
        int a, b;
        cin>>a>>b;
        v2.push_back(make_pair(a, b));
    }
    for(int i = 0; i<n; i++)
    {   ll mi = INT_MAX, ans = 1;
        for(int j = 0; j<m; j++)
        {
            ll x;
            ll a, b, c, d;
            a = v1[i].first;
            b = v2[j].first;
            c = v1[i].second;
            d = v2[j].second;

            x = abs(a-b) + abs(c - d);
            if(x<mi)
            {
                ans = j + 1;
                mi = x;
            }

        }
        cout<<ans<<endl;
    }

   return 0;

}

