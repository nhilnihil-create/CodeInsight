#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ss = 1e9;
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for(int i = -100;i <=100; i++)
    {    int cost=0;
        for(int j= 0; j < n; j++)
        {
            cost += (i-v[j]) * (i - v[j]);
        }
        ss=min(ss,cost);
    }
    cout<<ss<<"\n";
    return 0;
}