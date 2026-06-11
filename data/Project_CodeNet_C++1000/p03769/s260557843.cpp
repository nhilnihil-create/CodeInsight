#include <bits/stdc++.h>

using namespace std;

long long N;
deque <int> ans;
vector <int> dd;

void solve(long long N)
{
    if (N == 1) return;
    if (N%2 == 0)
    {
        solve(N/2);
        dd.push_back(1);
    }
    else
    {
        solve(N-1);
        dd.push_back(2);
    }
}

int main()
{
    cin >> N;
    solve(N+1);
    for (int i=0,j=1; i < dd.size(); i++, j++)
        if (dd[i] == 2) ans.push_front(j);
        else ans.push_back(j);
    int sz = ans.size();
    cout << sz*2 << endl;
    while (!ans.empty())
    {
        int x = ans.front();
        cout << x << " ";
        ans.pop_front();
    }
    for (int i=1; i <= sz; i++) cout << i << " ";
}
