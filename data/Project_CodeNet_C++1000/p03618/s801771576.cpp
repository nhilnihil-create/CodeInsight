#include <bits/stdc++.h>

using namespace std;

int freq[26];

int main()
{
    string a;
    cin >> a;
    int n = (int) a.length();
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        int key = a[i] - 'a';
        ans += i - freq[key];
        freq[key]++;
    }
    cout << ans << endl;
    return 0;
}
