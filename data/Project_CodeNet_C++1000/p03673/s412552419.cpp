#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vp vector<pair<int, int>>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

int main()
{
    int n;
    cin >> n;
    vi data(n+1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> data[i];
    }

    for(int i = n; i >= 1; i -= 2)
    {
        cout << data[i] << " ";
    }

    int j = (n%2 == 0) ? 1 : 2;

    for(; j <= n; j += 2)
    {
        cout << data[j] << " ";
    }
    cout << endl;

}
