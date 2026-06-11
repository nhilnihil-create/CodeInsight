#include <bits/stdc++.h>
using namespace std;

int main()  {
    string s;
    cin>>s;
    unordered_map<char,int> m;
    for(auto i:s)
        m[i]++;
    for(auto i:m)
    {
        if((i.second)%2)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}
