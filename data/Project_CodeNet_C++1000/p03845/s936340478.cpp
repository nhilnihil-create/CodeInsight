#include<bits/stdc++.h>
#include<string>
using namespace std;

typedef long long int lli;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<lli> v(n + 1);
    lli sum = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    int m;
    cin >> m;

    while(m--)
    {
        int p, x;
        cin >> p >> x;

        cout << sum - v[p] + x << endl;
    }


}
