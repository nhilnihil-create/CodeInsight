#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    int flag = 0;
    int a[26] = {0};
    cin >> s;
    for(int i = 0; i<s.length(); i++)
    {
        if(islower(s[i]))
        {
            a[s[i] - 'a']++;
        }
    }
    for(int i = 0; i<26; i++)
    {
        if(a[i]%2 != 0)
        {
            cout << "No";
            flag++;
            return 0;
        }
    }
    if(flag ==0)
    cout << "Yes";
    else cout << "No";
}