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
    int sum = 0;
    priority_queue<int> q;
    while(n--)
    {
        int s;
        cin >> s;
        sum += s;
        if(s%10 != 0)
        {
            q.push(-s);
        }
    }
    if(sum %10 == 0)
    {
        if(!q.empty())
        {
            sum -= -q.top();
        }
        else
        {
            sum = 0;
        }
    }
    cout << sum << endl;

}
