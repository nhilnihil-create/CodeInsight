#include <bits/stdc++.h>
using namespace std;
using Point = pair<int,int>;

int main()
{
    int N,K;
    cin >> N >> K;
    
    vector<long long> h(N);
    for(int i=0;i<N;i++)
    {
        cin >> h[i];
    }
    
    long long ans = LONG_LONG_MAX;
    for(int bit = 0;bit < (1<<N);bit++)
    {
        vector<int> used;
        for(int i=0;i<N;i++)
        {
            if(bit & (1 << i))
            {
                used.push_back(i);
            }
        }
        if(used.size() < K)
        {
            continue;
        }
        
        long long temp = 0;
        vector<long long> a(N);
        a=h;
        for(int i = 0;i<used.size();i++)
        {
            for(int j = 0;j<used[i];j++)
            {
                long long k =a[j]-a[used[i]] + 1;
                if(k>0)
                {
                    a[used[i]] += k;
                    temp += k;
                }
            }
        }
        ans = min(temp,ans);
    }
    
    cout << ans << endl;
    
    return 0;
}