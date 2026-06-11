#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

int main()
{
    int n;
    cin >> n;
    int t = 3*n;
    vi data(t);
    vll mxx(n+1), mnn(n+1); //k = n-1 to 2n-1
    for(int i = 0; i < t; i++)
    {
        cin >> data[i];
    }

    int k = n-1;
    ll mx = 0, mn = 0;
    priority_queue<int> q;
    for(int i = 0; i <= k; i++)
    {
        mx += data[i];
        q.push(-data[i]); //smallest on top
    }

    mxx[0] = mx;

    while(++k <= 2*n-1)
    {
        if(-data[k] < q.top())
        {
            mx -= -q.top();
            mx += data[k];
            q.pop();
            q.push(-data[k]);
        }
        mxx[k - (n-1)] = mx;
    }
    q = priority_queue<int>();

    reverse(data.begin(), data.end());

    k = n - 1;

    for(int i = 0; i <= k; i++)
    {
        mn += data[i];
        q.push(data[i]);
    }

    mnn[0] = mn;

    while(++k <= 2*n - 1)
    {
        if(data[k] < q.top())
        {
            mn -= q.top();
            mn += data[k];
            q.pop();
            q.push(data[k]);
        }
        mnn[k - (n-1)] = mn;
    }
    ll ans = -infll;
    for(int i = 0; i < n+1; i++)
    {
        ans = max(mxx[i] - mnn[n-i], ans);
    }

    cout << ans << endl;



}