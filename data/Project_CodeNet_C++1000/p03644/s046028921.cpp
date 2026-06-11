#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int first = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int counter = 0;
        int temp = i;
        while (temp % 2 == 0)
        {
            temp = temp / 2;
            counter++;
        }
        first = max(first, counter);
    }
    cout << pow(2, first);
}