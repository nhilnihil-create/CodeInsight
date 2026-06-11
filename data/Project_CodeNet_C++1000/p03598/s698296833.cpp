#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int robota = 0;
    int robotb = k;
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (((x - robota) * 2) > ((k - x) * 2))
        {
            counter += ((k - x) * 2);
        }
        else
        {
            counter += ((x - robota) * 2);
        }
    }
    cout << counter;
}