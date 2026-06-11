#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    stack<char> st;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'S') st.push('S');
        else
        {
            if(st.size() == 0 || st.top() == 'T') st.push('T');
            else st.pop();
        }
    }
    cout << st.size() << endl;
}
