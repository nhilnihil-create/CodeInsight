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

    vector<int> frequency(n + 1);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        frequency[x]++;
        if(x == 0 && frequency[x] == 2)
        {
            cout << 0;
            return 0;
        }

        if(frequency[x] > 2)
        {
            cout << 0;
            return 0;
        }
    }

    if(n%2 != 0)
    {
        n--;
    }

    n = n/2;
    lli product = 1;
    lli m = 1000000007;

    if(n == 0)
    {
        cout << 1 << endl;
        return 0;
    }


    while(n--)
    {
        product *= 2;
        product = product%m;
    }

    cout << product << endl;

}
