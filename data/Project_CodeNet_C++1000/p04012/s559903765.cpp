#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int c=0,i,j,n;
    for(i=0; i<s.length(); i++)
    {
        n=0;
        for(j=0; j<s.length(); j++)
        {
            if(s[i]==s[j])
                n++;
        }
        if(n%2==0)
            c++;
        else
            break;
    }
    if(c==s.length())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}

