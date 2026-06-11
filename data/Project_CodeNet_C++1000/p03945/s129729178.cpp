#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int ans=0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]!=s[i-1])
        {
            ans++;
        }
    }
    cout<<ans;
  	return 0;
}





