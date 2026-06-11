#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> x(n);
    for (int &t: x)
        cin>>t;
    long long M = 1000000007;
    long long ans = 1;
    int cnt = 1;
    int cur = 1;
    int p = 1;
    while (cur<n)
    {
        while (cur<n && (cnt-1)*2+2<x[cur])
        {
            cur++;
            cnt++;
        }
        if (cur<n)
        {
            ans = ans * (cnt+1) % M;
            cur++;
        }
    }
    while (cnt>1)
        ans = ans * cnt % M,
        cnt--;
    cout<<ans<<endl;
}

