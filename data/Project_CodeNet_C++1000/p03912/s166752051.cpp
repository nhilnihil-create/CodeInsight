#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;

int n, m;
vector<int> v[Nmax];

int solve(vector<int> &a, vector<int> &b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int leftA, leftB, matA = 0, matB = 0;
    int i;

    for(i=0; i<a.size(); ++i)
        if(i+1<a.size() && a[i] == a[i+1])
        {
            a[i] = a[i+1] = -1;
            ++matA;
        }

     for(i=0; i<b.size(); ++i)
        if(i+1<b.size() && b[i] == b[i+1])
        {
            b[i] = b[i+1] = -1;
            ++matB;
        }

    leftA = ((int)a.size() - 2*matA);
    leftB = ((int)b.size() - 2*matB);


    int ans;

    if(leftA > leftB)
        swap(leftA, leftB), swap(matA, matB);

    ans = leftA;
    leftB -= leftA;

    while(matA>0 && leftB>=2)
        leftB-=2, ans+=2, matA--;

    ans += matA;
    ans += matB;

    return ans;
}

int main()
{
//    freopen("input", "r", stdin);
    cin.sync_with_stdio(false); cin.tie(0);


    cin >> n >> m;
    int i;
    for(i=1; i<=n; ++i)
    {
        int x;
        cin >> x;
        v[x%m].push_back(x);
    }

    int ans = 0;

    for(i=0; i<m; ++i)
        if(i == 0 || i==m-i)
            ans += (int)v[i].size() / 2;
        else
            if(i < m-i)
                ans += solve(v[i], v[m-i]);

    cout << ans << '\n';

    return 0;
}
