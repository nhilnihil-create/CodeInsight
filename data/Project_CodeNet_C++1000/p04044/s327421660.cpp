#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, l;

    cin >> n >> l;

    deque<string> str(n);

    for(int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    sort(str.begin(), str.end());

    for(int i = 0; i < n; i++)
    {
        cout << str[i];
    }

    cout << endl;

    return 0;
}
