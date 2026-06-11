#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,count = 0;
    unordered_map<int,int> m;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        m[temp]++;
    }
    for(auto x : m)
    {
        if(x.second % 2 == 0)
            count++;
    }
    if(count & 1)
        cout<<(m.size() - 1)<<endl;
    else
        cout<<(m.size())<<endl;
    return 0;
}
