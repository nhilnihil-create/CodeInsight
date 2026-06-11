#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = s;
    vector<bool> used(n);
    for(int i = 0; s[i]; i++)
    {
        if (s[i] == '(')
        {
            bool found = 0;
            for(int j = i+1; s[j]; j++)
            {
                if(s[j] == ')' && !used[j])
                {
                    used[j] = 1;
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                ans += ")";
            }
        }
    }

    for(int i = n-1; i >= 0; i--)
    {
        if(s[i] == ')')
        {
            bool found = 0;
            for(int j = i-1; j >= 0; j--)
            {
                if(s[j] == '(' && !used[j])
                {
                    used[j] = 1;
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                string temp = ans;
                ans = "(" + temp;
            }
        }
    }

    cout << ans << endl;
}