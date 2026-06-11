#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

long long arr[N];
int solve()
{
    string s;
    cin>>s;
    int n=s.size();
    stack<char> ans;
    for(int i=0;i<n;i++)
    {
       if(s[i]=='B') {
           if (ans.size())
               ans.pop();
       }
       else
           ans.push(s[i]);
    }
    s="";
    while(ans.size())
    {
        s+=ans.top();
        ans.pop();
    }
    reverse(s.begin(), s.end());
    cout<<s;
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
   // freopen("input.txt" ,"r" ,stdin);
   // freopen("output.txt" ,"w" ,stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   // int t;
   // cin>>t;
   // while(t--)
        solve();

    return 0;
}