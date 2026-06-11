

#include<bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL);

int main()
{
    speed;

    string s,ans;
    cin>>s;

    stack<char>st;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='B') st.push(s[i]);

        else if(s[i]=='B' && !st.empty()) st.pop();
    }

    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    cout<<ans<<"\n";
}