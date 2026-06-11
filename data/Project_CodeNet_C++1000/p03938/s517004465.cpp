#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> p(n), a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
        a[i] = 30000 * (i + 1);
        b[i] = 30000 * (n - i - 1) + 1;
    }
    for(int i=0; i<n; i++){
        a[p[i]]+=i;
    }
    for (auto &p : a)
        cout << p << " ";
    cout << endl;
    for (auto &p : b)
        cout << p << " ";
}