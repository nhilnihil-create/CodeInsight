#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    cin>>s;
    int c[26] ={0};
    for(int i=0;i<s.length();i++)
    {
        c[s[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(c[i]%2==1)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;

}
