#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100
int n, m;
bool foundsquare(int y, int x, vector<string> a, vector<string> b)
{
    for(int i = y; i < y + m; i++)
    {
        for(int j = x; j < x + m; j++)
        {
            if(a[i][j] != b[i-y][j-x])
            {
                return false;
            }
        }
    }

    return true;
}


int main()
{
    cin >> n >> m;
    vector<string> a(n), b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    bool solve = 0;

    for(int i = 0; i <= n-m; i++)
    {
        for(int j = 0; j <= n-m; j++)
        {
            if(foundsquare(i, j, a, b))
            {
                solve = 1;
                break;
            }
        }
    }

    if(solve) cout << "Yes" << endl;
    else cout << "No" << endl;
}
