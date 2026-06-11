#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
const int N = 105;

int n;
int a[N], cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    sort(a + 1, a + n + 1);

    if(a[1] < (a[n] + 1) / 2)
    {
        cout << "Impossible" << endl;
        return 0;
    }

    for(int i = 0; i <= a[n]; i++)
    {
        int d = max(i, a[n] - i);
        cnt[d]--;

        if(cnt[d] == -1)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }


    if(cnt[(a[n] + 1) / 2])
        cout << "Impossible" << endl;
    else
        cout << "Possible" << endl;

    return 0;
}
