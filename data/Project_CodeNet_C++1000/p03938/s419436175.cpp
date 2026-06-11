#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    for(int i = 1; i <= n; i++)
    {
        cout << i * 20000 << " ";
    }
    cout << endl;

    for(int i = 1; i <= n; i++)
    {
        int pos = distance(p.begin(), find(p.begin(), p.end(), i));
        cout << (n-i) * 20000 + pos+1 << " ";
    }
    cout << endl;
}
