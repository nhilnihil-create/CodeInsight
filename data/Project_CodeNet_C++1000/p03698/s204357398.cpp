#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int a[26]={0};
    cin>>s;
    for (size_t i = 0; i < s.length(); i++)
    {
        a[s[i] - 'a'] += 1;
    }
    for (size_t i = 0; i < 26; i++)
    {
        if(a[i]>1){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;

    return 0;
}