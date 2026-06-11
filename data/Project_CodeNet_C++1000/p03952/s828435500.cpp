#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 5;

int n, k;
int alive[2 * N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    if(k == 1 || k == 2 * n - 1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        if(n == 2)
        {
            cout << 1 << endl << 2 << endl << 3 << endl;
            return 0;
        }

        memset(alive, true, sizeof(alive));
        alive[k] = false;
        alive[k - 1] = false;
        alive[k + 1] = false;
        if(k > 2)
            alive[k - 2] = false;
        else
            alive[k + 2] = false;

        int j = 1;
        for(int i = 1; i <= 2 * n - 1; i++)
        {
            if(i == n  - 1)
            {
                if(k == 2)
                {
                    cout << k + 1 << endl << k << endl << k - 1 << endl << k + 2 << endl;
                }
                else
                {
                    cout << k - 1 << endl << k << endl << k + 1 << endl << k - 2 << endl;
                }
                i += 3;
                continue;
            }

            while(!alive[j])
                j++;
            cout << j << endl;
            alive[j] = false;
        }
    }


    return 0;
}
