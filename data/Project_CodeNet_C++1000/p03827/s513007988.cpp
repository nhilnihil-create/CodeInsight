#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x=0,n;
    cin >> n;
    string s;
    cin >> s;
    int m_ans = x;
    for(int i=0;i<s.length();i++){
        if(s[i]=='I')
            x++;
        else
            x--;
        m_ans = max(m_ans,x);
    }
    cout << m_ans;
    return 0;
}