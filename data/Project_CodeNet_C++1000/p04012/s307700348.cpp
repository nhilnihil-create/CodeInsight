#include<bits/stdc++.h>
using namespace std;
string s;
int a[50];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int i,j,c=1,d;
    for(i=0; i<s.length(); i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            a[s[i]-'a']++;
        }

    }
    for(i=0; i<26; i++)
    {
        if(a[i]%2!=0)
        {
            c=0;
            break;
        }
    }
    if(c==0)
    {
        cout<<"No\n";
    }
    else
        cout<<"Yes\n";




    return 0;
}

