#include <bits/stdc++.h>
using namespace std;

stack<char> st;
string s;
int l;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;++i)
    {
        if(st.empty()||!(st.top()=='S'&&s[i]=='T')) st.push(s[i]);
        else st.pop();
    }
    cout<<st.size();
    return 0;
}