#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, bool> sheet;
    int answer = 0;

    while (n--)
    {
        int x;
        cin >> x;
        if (sheet[x])
            sheet[x] = 0;
        else
            sheet[x] = 1;
    }

    for (auto number : sheet)
        if (number.second)
            answer++;

    cout << answer << endl;
    return 0;
}
