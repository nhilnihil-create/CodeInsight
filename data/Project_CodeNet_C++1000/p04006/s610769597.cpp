#include <bits/stdc++.h>
using namespace std;
int N;
long x;

int f(int t)
{
    if(t < 0)
    {
        t += N;
    }
    return t;
}

int main()
{
    
    cin >> N;
    cin >> x;
    
    vector<vector<long>> data(N,vector<long>(N));
    
    
    for(int i=0;i<N;i++)
    {
        cin >> data[i][0];
    }
    
    for(int j = 1;j<N;j++)
    {
        data[0][j] = data[N-1][j-1] + x;
        for(int i=1;i<N;i++)
        {
            data[i][j] = data[i-1][j-1] + x;
        }
    }
    
    vector<long> ans(N,0);
    vector<long> mini(N);
    mini = data[0];

    for(int k = 0;k<N;k++) //魔法回数
    {
        long temp = 0;
        for(int i = 0;i<N;i++)
        {
            mini[i] = min(mini[i],data[f(i-k)][0]);
            temp += mini[i];
        }
        ans[k] = temp + k * x;
    }
    
    
    sort(ans.begin(),ans.end());
    
    cout << ans[0] << endl;
    
    return 0;
    
}