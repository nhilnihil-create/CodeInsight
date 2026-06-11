#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();
    stack<char>s1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B')
        {
            if(!s1.empty())
            {
                s1.pop();
            }
        }
        else
        {
            s1.push(s[i]);
        }
    }
    string ans;
    while(!s1.empty())
    {
        ans+=s1.top();
        s1.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}





