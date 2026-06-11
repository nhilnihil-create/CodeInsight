#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define endl '\n'
using namespace std;
const int N = 2e4 + 5;

int n, p[N];
int a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[n - i + 1];

        a[i] = i;
        b[i] = n - i + 1;
    }

    b[0] = 2e9;
    a[n + 1] = 2e9;
    int cur_add = n - 1;
    for(int i = 1; i <= n; i++, cur_add--)
    {
        b[p[i]] += cur_add;
        if(b[p[i]] >= b[p[i] - 1])
        {
            int diff = b[p[i]] - b[p[i] - 1] + 1;
            for(int j = 1; j < p[i]; j++)
            {
                b[j] += diff;
                a[j] -= diff;
            }
        }
    }

    int mn_a = *min_element(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        cout << a[i] - mn_a + 1 << ' ';
    cout << endl;
    for(int i = 1; i <= n; i++)
        cout << b[i] << ' ';
    cout << endl;


    return 0;
}
