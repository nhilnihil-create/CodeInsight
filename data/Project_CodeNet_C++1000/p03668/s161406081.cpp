#include<bits/stdc++.h>
using namespace std;

vector<int> v[100005];
int a[100005];

int dfs(int n  , int p)
{
    a[n] = 0;

    for(int it : v[n])
    {
        if(it==p)
            continue;
        dfs(it , n);
        a[n] ^= a[it]+1;
    }
}

int main()
{
    int n;

    cin >> n;

    for(int i = 1 ; i<n ; i++)
    {
        int x , y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1 , 0);

    if(a[1]==0)
    {
        cout << "Bob";
        return 0;
    }
    else
    cout << "Alice";
    return 0;
}
