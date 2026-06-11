#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l;
    cin>>n>>l;
    vector<string>s;
    for(int i=0;i<n;i++)
    {
        string s1;
        cin>>s1;
        s.push_back(s1);
    }
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++)
    {
        cout<<s[i];
    }
    return 0;
}





